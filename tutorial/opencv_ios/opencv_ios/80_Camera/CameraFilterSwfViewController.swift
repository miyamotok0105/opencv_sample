//
//  CameraFilterSwfViewController.swift
//  opencv_ios
//
//  Created by USER on 2017/11/26.
//  Copyright © 2017年 USER. All rights reserved.
//

import UIKit
import AVFoundation

class CameraFilterSwfViewController: UIViewController, AVCaptureVideoDataOutputSampleBufferDelegate,UIGestureRecognizerDelegate {

    var input:AVCaptureDeviceInput!
    var output:AVCaptureVideoDataOutput!
    var session:AVCaptureSession!
    var camera:AVCaptureDevice!
    @IBOutlet weak var imageView: UIImageView!
    var filter:String = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // 画面タップでシャッターを切るための設定
        let tapGesture:UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(CameraSwfViewController.tapped(_:)))
        // デリゲートをセット
        tapGesture.delegate = self;
        // Viewに追加.
        self.view.addGestureRecognizer(tapGesture)
        
    }

    override func viewWillAppear(_ animated: Bool) {
        // カメラの設定
        setupCamera()
    }
    
    
    func setupCamera(){
        // AVCaptureSession: キャプチャに関する入力と出力の管理
        session = AVCaptureSession()
        
        // sessionPreset: キャプチャ・クオリティの設定
        session.sessionPreset = AVCaptureSessionPresetHigh
        //        session.sessionPreset = AVCaptureSessionPresetPhoto
        //        session.sessionPreset = AVCaptureSessionPresetHigh
        //        session.sessionPreset = AVCaptureSessionPresetMedium
        //        session.sessionPreset = AVCaptureSessionPresetLow
        
        // 背面・前面カメラの選択 iOS10での変更
        camera = AVCaptureDevice.defaultDevice(withDeviceType: .builtInWideAngleCamera,
                                               mediaType: AVMediaTypeVideo,
                                               position: .back) // position: .front
        
        
        // カメラからの入力データ
        do {
            input = try AVCaptureDeviceInput(device: camera) as AVCaptureDeviceInput
        } catch let error as NSError {
            print(error)
        }
        
        
        // 入力をセッションに追加
        if(session.canAddInput(input)) {
            session.addInput(input)
        }
        
        // AVCaptureStillImageOutput:静止画
        // AVCaptureMovieFileOutput:動画ファイル
        // AVCaptureAudioFileOutput:音声ファイル
        // AVCaptureVideoDataOutput:動画フレームデータ
        // AVCaptureAudioDataOutput:音声データ
        
        // AVCaptureVideoDataOutput:動画フレームデータを出力に設定
        output = AVCaptureVideoDataOutput()
        // 出力をセッションに追加
        if(session.canAddOutput(output)) {
            session.addOutput(output)
        }
        
        // ピクセルフォーマットを 32bit BGR + A とする
        output.videoSettings = [kCVPixelBufferPixelFormatTypeKey as AnyHashable : Int(kCVPixelFormatType_32BGRA)]
        
        // フレームをキャプチャするためのサブスレッド用のシリアルキューを用意
        output.setSampleBufferDelegate(self, queue: DispatchQueue.main)
        
        output.alwaysDiscardsLateVideoFrames = true
        
        // ビデオ出力に接続
        //        let connection  = output.connection(withMediaType: AVMediaTypeVideo)
        
        session.startRunning()
        
        // deviceをロックして設定
        // swift 2.0
        do {
            try camera.lockForConfiguration()
            // フレームレート
            camera.activeVideoMinFrameDuration = CMTimeMake(1, 30)
            
            camera.unlockForConfiguration()
        } catch _ {
        }
    }
    
    // 新しいキャプチャの追加で呼ばれる
    func captureOutput(_ captureOutput: AVCaptureOutput!, didOutputSampleBuffer sampleBuffer: CMSampleBuffer!, from connection: AVCaptureConnection!) {
        
        // キャプチャしたsampleBufferからUIImageを作成
        let image:UIImage = self.captureImage(sampleBuffer)
        
        // 画像を画面に表示
        DispatchQueue.main.async {
            self.imageView.image = image
            
        }
    }
    
    // sampleBufferからUIImageを作成
    func captureImage(_ sampleBuffer:CMSampleBuffer) -> UIImage{
        
        // Sampling Bufferから画像を取得
        let imageBuffer:CVImageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer)!
        
        // pixel buffer のベースアドレスをロック
        CVPixelBufferLockBaseAddress(imageBuffer, CVPixelBufferLockFlags(rawValue: CVOptionFlags(0)))
        
        let baseAddress:UnsafeMutableRawPointer = CVPixelBufferGetBaseAddressOfPlane(imageBuffer, 0)!
        
        let bytesPerRow:Int = CVPixelBufferGetBytesPerRow(imageBuffer)
        let width:Int = CVPixelBufferGetWidth(imageBuffer)
        let height:Int = CVPixelBufferGetHeight(imageBuffer)
        
        
        // 色空間
        let colorSpace:CGColorSpace = CGColorSpaceCreateDeviceRGB()
        
        //let bitsPerCompornent:Int = 8
        // swift 2.0
        let newContext:CGContext = CGContext(data: baseAddress, width: width, height: height, bitsPerComponent: 8, bytesPerRow: bytesPerRow, space: colorSpace,  bitmapInfo: CGImageAlphaInfo.premultipliedFirst.rawValue|CGBitmapInfo.byteOrder32Little.rawValue)!
        
        let imageRef:CGImage = newContext.makeImage()!
        var resultImage = UIImage(cgImage: imageRef, scale: 1.0, orientation: UIImageOrientation.right) //rightでhomeボタンが下にくる
        
        if filter != "" {
            resultImage = outputImage(originalImage: resultImage, filter: CIFilter(name: filter))
        }
        
        return resultImage
    }
    
    // タップイベント.
    func tapped(_ sender: UITapGestureRecognizer){
        print("タップ")
        takeStillPicture()
    }
    
    func takeStillPicture(){
        if var _:AVCaptureConnection? = output.connection(withMediaType: AVMediaTypeVideo){
            // アルバムに追加
            UIImageWriteToSavedPhotosAlbum(self.imageView.image!, self, nil, nil)
        }
        
    }
    
    lazy var context: CIContext = {
        return CIContext(options: nil)
    }()
    
    func outputImage(originalImage: UIImage, filter: CIFilter!) -> UIImage {
        print(filter)
        let inputImage = CIImage(image: originalImage)
        filter.setValue(inputImage, forKey: kCIInputImageKey)
        let outputImage =  filter.outputImage!
        if let cgImage = context.createCGImage(outputImage, from: outputImage.extent) {
            return UIImage(cgImage: cgImage, scale: 1.0, orientation: UIImageOrientation.right)
        }
        return UIImage()
    }
    
    
    @IBAction func originalAction(_ sender: Any) {
        filter = ""
    }
    
    @IBAction func cIPhotoEffectInstantAction(_ sender: Any) {
        filter = "CIPhotoEffectInstant"
    }
    
    @IBAction func cIPhotoEffectNoirAction(_ sender: Any) {
        filter = "CIPhotoEffectNoir"
    }
    
    @IBAction func cIPhotoEffectTonalAction(_ sender: Any) {
        filter = "CIPhotoEffectTonal"
    }
    
    @IBAction func cIPhotoEffectTransferAction(_ sender: Any) {
        filter = "CIPhotoEffectTransfer"
    }
    
    @IBAction func cIPhotoEffectFadeAction(_ sender: Any) {
        filter = "CIPhotoEffectFade"
    }
    
    @IBAction func cIPhotoEffectProcessAction(_ sender: Any) {
        filter = "CIPhotoEffectProcess"
    }
    
    @IBAction func cIPhotoEffectChromeAction(_ sender: Any) {
        filter = "CIPhotoEffectChrome"
    }
    
    @IBAction func cIPhotoEffectMonoAction(_ sender: Any) {
        filter = "CIPhotoEffectMono"
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}

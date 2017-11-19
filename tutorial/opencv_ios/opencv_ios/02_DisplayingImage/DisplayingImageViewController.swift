//
//  DisplayingImageViewController.swift
//  opencv_ios
//
//  Created by USER on 2017/11/20.
//  Copyright © 2017年 USER. All rights reserved.
//

import UIKit

class DisplayingImageViewController: UIViewController {

    @IBOutlet weak var imageView: UIImageView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        print("DisplayingImageViewController Load")
        
        // Read the image
        let image1:UIImage = UIImage(named:"lena")!
        print(image1)
        imageView.image = image1
        print(imageView)
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

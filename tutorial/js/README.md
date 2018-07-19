

基本これで動くはず。    
https://qiita.com/r_i_qita/items/2b30c1beb99eea93f496



Python2.7を使う。    
--emscriptenのパスは絶対パス！！    


```
python ./platforms/js/build_js.py build_js --emscripten /hogehoge/emsdk-portable/emscripten/1.38.8

ls build_js/bin
python -m SimpleHTTPServer
```


http://localhost:8000/


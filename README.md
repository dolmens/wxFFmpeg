# wxFFmpeg - wxWidgets FFmpeg view library

The wxFFmpeg is a wxWidgets FFmpeg player library. It uses OpenGL(by GLEW) to render the video texture, and OpenAL(OpenAL-soft) to play audio.

## License
LGPL version 3.

## Build
### Prerequirements
- wxWidgets 3.0.5+
- FFmpeg 3.0+
- OpenGL 3.3+

```bash
git submodule update --init
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -v
# run the example
./build/example/wxFFmpegPlayer your.mp4
```
  
## Usage
It's rather simple, just embed the wxFFmpegView and call the open method.

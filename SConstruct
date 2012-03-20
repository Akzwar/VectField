OF = Environment()
OF.ParseConfig('pkg-config glew gstreamer-0.10 gstreamer-video-0.10 gstreamer-base-0.10 libudev gtk+-2.0 --cflags')
OF.ParseConfig('''pkg-config gtk+-2.0 jack glew gstreamer-0.10 \
gstreamer-video-0.10 gstreamer-base-0.10 gstreamer-app-0.10 libudev cairo --libs''')
OF.Append(CPPPATH = ["/usr/include/",
			"../OpenFrameworks/libs/openFrameworks/",
			"../OpenFrameworks/libs/openFrameworks/utils/",
			"../OpenFrameworks/libs/openFrameworks/3d/",
			"../OpenFrameworks/libs/openFrameworks/communication/",
			"../OpenFrameworks/libs/openFrameworks/gl/",
			"../OpenFrameworks/libs/openFrameworks/math/",
			"../OpenFrameworks/libs/openFrameworks/sound/",
			"../OpenFrameworks/libs/openFrameworks/utils/",
			"../OpenFrameworks/libs/openFrameworks/app/",
			"../OpenFrameworks/libs/openFrameworks/events/",
			"../OpenFrameworks/libs/openFrameworks/graphics/",
			"../OpenFrameworks/libs/openFrameworks/types/",
			"../OpenFrameworks/libs/openFrameworks/video/",
			"../OpenFrameworks/libs/assimp/include/",
			"../OpenFrameworks/libs/FreeImage/include/",
			"../OpenFrameworks/libs/kiss/include/",
			"../OpenFrameworks/libs/rtAudio/include/",
			"../OpenFrameworks/libs/cairo/include/cairo/",
			"../OpenFrameworks/libs/cairo/include/libpng15/",
			"../OpenFrameworks/libs/cairo/include/pixman-1/",
			"../OpenFrameworks/libs/cairo/include/",
			"../OpenFrameworks/libs/freetype/include/freetype2/",
			"../OpenFrameworks/libs/freetype/include/",
			"../OpenFrameworks/libs/poco/include/CppUnit/",
			"../OpenFrameworks/libs/poco/include/Poco/",   
			"../OpenFrameworks/libs/poco/include/Poco/DOM/",
			"../OpenFrameworks/libs/poco/include/Poco/Dynamics/",
			"../OpenFrameworks/libs/poco/include/Poco/Net/",
			"../OpenFrameworks/libs/poco/include/Poco/SAX/",
			"../OpenFrameworks/libs/poco/include/Poco/Util/",
			"../OpenFrameworks/libs/poco/include/Poco/XML/",
			"../OpenFrameworks/libs/poco/include/",
			"../OpenFrameworks/libs/tess2/include/",
			"../OpenFrameworks/libs/fmodex/include/",
			"../OpenFrameworks/libs/glew/include/",
			"../OpenFrameworks/libs/glew/include/GL/"
			]
	)
OF.Append(LIBPATH = ["/usr/lib/",
			"../OpenFrameworks/libs/openFrameworksCompiled/lib/linux/",
			"../OpenFrameworks/libs/poco/lib/linux/",
            "../OpenFrameworks/libs/kiss/lib/linux/",
            "../OpenFrameworks/libs/portaudio/lib/linux/",
            "../OpenFrameworks/libs/tess2/lib/linux/",
            "../OpenFrameworks/libs/rtAudio/lib/linux/"
		]
	)
OF.Append(LIBS = [
			"GL",
            "asound",
            "sndfile",
            "vorbis",
            "FLAC",
            "ogg",
            "GLU",
            "glut",
            "GLEW",
			"openal",
			"openFrameworks",
			"openFrameworksDebug",
			"pthread",
			"PocoFoundation",
			"PocoUtil",
			"PocoNet",
			"PocoXML",
			"cairo",
			"freeimage",
            "kiss",
            "fmodex",
            "freetype",
            "portaudio",
            "RtAudio",
            "tess2"
		]
	)
sources=Split('''
src/main.cpp
src/testApp.cpp
src/fft.cpp
src/particles.cpp
''')
obj_list=OF.Object(source=sources)
OF.Program(target = "bin/VectField", source = obj_list)


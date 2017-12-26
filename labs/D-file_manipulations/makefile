
CXX = labD.cpp
CXX += Transformer.cpp
CXX += Transformer.hpp
CXX += Copy.cpp
CXX += Copy.hpp
CXX += Encryption.cpp
CXX += Encryption.hpp
CXX += ToUpper.cpp
CXX += ToUpper.hpp
CXX += OrderedOutput.cpp
CXX += OrderedOutput.hpp


labD: labD.cpp Transformer.cpp Transformer.hpp Copy.cpp Copy.hpp Encryption.cpp ToUpper.cpp OrderedOutput.cpp OrderedOutput.hpp
	g++ -std=c++0x labD.cpp Transformer.cpp Copy.cpp Encryption.cpp ToUpper.cpp OrderedOutput.cpp -o manipulate


clean:
	rm manipulate



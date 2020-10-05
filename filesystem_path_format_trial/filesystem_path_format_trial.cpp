// This is an example code for filepath format conversions using std::filesystem
// A string input, supposedly represents a file path, can be readily switched between different
// file path formats, specifically between UNIX one and Windows ones
// 2020.10.5
// Ahn, Jeeho

#include <filesystem>
#include <string>
#include <iostream>

int main()
{
	//below c++17, the filesystem library is in std::experimental
	//from c++17, it is known to be in std like other members
	std::cout << "STD Filesystem format conversion demonstration" << std::endl;

	// Windows style of a file path
	std::string file_path_raw = "C:\\sample\\file\\path.txt";
	std::cout << "\nOriginal Path String: \n" << file_path_raw << std::endl;

	// constructing a std::filesystem type
	std::experimental::filesystem::path file_path(file_path_raw);

	// convert it into UNIX format (or the one I prefer)
	std::string file_path_unix = file_path.generic_string();
	std::cout << "\nUNIX format: \n" << file_path_unix << std::endl;

	// or in one line of code
	std::string file_path_unix2 = std::experimental::filesystem::path(file_path_raw).generic_string();
	std::cout << "\nUNIX format by one line of code: \n" << file_path_unix2 << std::endl;

	// convert it back into Windows format
	std::string file_path_windows = file_path.make_preferred().string();
	std::cout << "\nWindows format: \n" << file_path_windows << std::endl;

	return 0;
}

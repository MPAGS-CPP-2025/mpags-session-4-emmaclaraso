#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <boost/program_options.hpp>

namespace po = boost::program_options;


int main(int argc, char* argv[]){
    // Initialise variables
    char c{'x'};
    std::string out_text;
    std::string input_file;

    // Define command-line options
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("i", po::value<std::string>(&input_file), "Name of input file");

    // Parse the command line
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    // Show help
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 0;
    }

    // Use the input file
    if (vm.count("i")) {
        std::cout << "Input file: " << input_file << "\n";
    } else {
        std::cout << "No input file provided. Use --help for options.\n";
    }

    return 0;



    /*
    const std::vector<std::string> cmdLineArgs { argv, argv+argc };

        
        for(int i=0; i < cmdLineArgs.size(); i++){

            if ((cmdLineArgs[i] == "--help") || (cmdLineArgs[i] == "-h")) {
                std::cout << "Help message \n" << std::endl;
            }

            if (cmdLineArgs[i] == "--version") {
                std::cout << "Version \n" << std::endl;
            }

            if (cmdLineArgs[i] == "-o") {
                std::string out_file{cmdLineArgs[i+1]};
                std::cout << out_file << std::endl;
                i++;
            }
            
            if (cmdLineArgs[i] == "-i") {
                std::string in_file{cmdLineArgs[i+1]};
                std::cout << in_file << std::endl;
                i++;
            }

            //std::cout << cmdLineArgs[i] << std::endl;
        }
            */


    // loop over each character from user input
    while (std::cin >> c) {

        {
        
        // Uppercase alphabetic characters
        if (std::isalpha(c)) {
            out_text += std::toupper(c);
            continue;
        }

        // Transliterate digits to English words
        switch (c) {
            case '0':
                out_text += "ZERO";
                break;
            case '1':
                out_text += "ONE";
                break;
            case '2':
                out_text += "TWO";
                break;
            case '3':
                out_text += "THREE";
                break;
            case '4':
                out_text += "FOUR";
                break;
            case '5':
                out_text += "FIVE";
                break;
            case '6':
                out_text += "SIX";
                break;
            case '7':
                out_text += "SEVEN";
                break;
            case '8':
                out_text += "EIGHT";
                break;
            case '9':
                out_text += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << out_text << std::endl;
}
}
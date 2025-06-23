#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    for (char& c : lowerStr) c = std::tolower(c);
    return lowerStr;
}

void HTMLfiletemplate() 
{
    std::string filename;
    std::string title;
    std::string cssPath;
    std::string jsPath;

    std::cout << "Enter HTML filename (e.g., index.html): ";
    std::getline(std::cin >> std::ws, filename);
    if (filename.empty()) filename = "index.html";

    std::cout << "Enter page title: ";
    std::getline(std::cin, title);
    if (title.empty()) title = "Document";

    std::cout << "Enter CSS file path (leave empty if none): ";
    std::getline(std::cin, cssPath);

    std::cout << "Enter JS file path (leave empty if none): ";
    std::getline(std::cin, jsPath);

    std::ofstream html(filename);

    if (html.is_open()) {
        html << "<!DOCTYPE html>\n";
        html << "<html lang=\"en\">\n";
        html << "<head>\n";
        html << "    <meta charset=\"UTF-8\">\n";
        html << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";

        if (!cssPath.empty()) {
            html << "    <link rel=\"stylesheet\" href=\"" << cssPath << "\">\n";
        } else {
            html << "    <link rel=\"stylesheet\" href=\"\"> <!--(optional) Link an external .css file-->\n";
        }

        html << "    <title>" << title << "</title>\n";
        html << "</head>\n";
        html << "<body>\n\n";

        if (!jsPath.empty()) {
            html << "    <script src=\"" << jsPath << "\"></script>\n";
        } else {
            html << "    <script src=\"\"></script> <!--(optional) Link an  external .js file -->\n";
        }

        html << "</body>\n";
        html << "</html>\n";
        html.close();

        std::cout << filename << " template generated successfully.\n";
    } else {
        std::cout << "Failed to create " << filename << "\n";
    }
}


void CPPfiletemplate()
{
    std::string filename;
    std::string funcName;

    std::cout << "Enter filename (e.g., utils.cpp): ";
    std::getline(std::cin >> std::ws, filename);

    if (filename.empty()) {
        filename = "main.cpp";
    }

    std::cout << "Enter function name: ";
    std::getline(std::cin, funcName);

    if (funcName.empty()) {
        funcName = "function";
    }

    std::ofstream file(filename);

    if (file.is_open()) {
        file << "#include <iostream>\n";
        file << "#include <cstdlib>\n";
        file << "#include <vector>\n\n";
        file << "void " << funcName << "()\n";
        file << "{\n";
        file << "    // TODO: Implement this function\n";
        file << "}\n\n";
        file << "int main() \n";
        file << "{\n";
        file << "    // Entry point\n";
        file << "    return 0;\n";
        file << "}\n";

        file.close();
        std::cout << filename << " template written successfully.\n";
    } else {
        std::cerr << "Failed to create " << filename << ".\n";
    }
}

int main() {
    system("title myCLI");
    system("chcp 65001 > nul");
    std::string command;
    std::string inputLine;

    while (true)
    {
        std::cout << "\n$ ";
        std::getline(std::cin, inputLine);

        if (inputLine.empty()) continue;

        std::istringstream iss(inputLine);
        iss >> command;

        if (command.empty()) continue;

        std::string cmdLower = toLower(command);

        if (cmdLower == "htmltemplate") {
            HTMLfiletemplate();
        } else if (cmdLower == "cpptemplate") {
            CPPfiletemplate();
        } else if (cmdLower == "cmd" || cmdLower == "powershell") {
            std::cout << "You're already in a shell, bro.\n";
        } else if (cmdLower == "clear") {
            system("cls");
        } else if (cmdLower == "version") {
            std::cout << "\nWindows 11 [v1.0]";
            std::cout << "\n(c) Floppacodesthis. All rights reserved\n";
        } else if (cmdLower == "test") {
            std::cout << "works!\n";
        } else if (cmdLower == "exit") {
            std::cout << "Goodbye!\n";
            break;
        } else {
            system(inputLine.c_str());
        }
    }

    return 0;
}

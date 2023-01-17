#include <iostream>
#include <string>
#include <set>
#include <map>

std::set<std::string> make_exit_commands() {
    std::set<std::string> commands;
    commands.emplace("q");// "quit", "e", "exit");
    commands.emplace("quit");
    commands.emplace("e");
    commands.emplace("exit");
    return commands;
}

void add(const std::string& command, std::map<std::string, std::string>& map) {
    auto pos = command.find(' ');
    auto key =  command.substr(0, pos); 
    auto value = command.substr(pos + 1);
    map.insert_or_assign(key, value);
    std::cout << key << " => " << value << std::endl;

}

/*
std::string translate(const std::string& command, std::map<std::string, std::string>& map){
    auto search = map.find(command);
    if (search != map.end()) {
        return 
    }
}
*/

void parse_command(const std::string& command, std::map<std::string, std::string>& map) {
    //std::cerr << "input: " << command << std::endl;
    std::string::size_type pos = command.find(' ');
    auto c = command.substr(0, pos);
    //std::cout << "avant pos " << c << "\n"; 
    if (c.compare("add") == 0) {
        //std::cout << "après pos " << command.substr(pos + 1) << "\n";
        add(command.substr(pos + 1), map);
    } else if (c.compare("translate") == 0) {

    }
}



int main()
{
    std::map<std::string, std::string> map;
    while (true)
    {
        std::string input;
        std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        // std::cin >> input;
        getline (std::cin, input);
        auto exit_commands = make_exit_commands(); 
        if (exit_commands.count(input) != 0) {
            return 0; 
        }
        parse_command(input, map); 
    }

    return 0;
}
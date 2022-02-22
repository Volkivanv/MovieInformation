#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>

int main() {

    nlohmann::json movie = {
            {"name", "Pulp Fiction"},
            {"country", "USA"},
            {"date", 1994},
            {"studio", "A Band Apart"},
            {"scenario author", "Quentin Tarantino"},
            {"director", "Quentin Tarantino"},
            {"producer", "Lawrence Bender"},
            {"Vincent Vega", "John Travolta"},
            {"Jules Winnfield", "Samuel L. Jackson"},
            { "Butch Coolidge", "Bruce Willis" },
            { "Mia Wallace", "Uma Thurman" }
    };

    std::ofstream file("movieInfo.json");
    if(file) {
        file << movie;
    } else {
        std::cerr<<"file is not opened";
    }
    file.close();

    std::ifstream rFile("movieInfo.json");

    nlohmann::json oMovie;
    rFile >> oMovie;

    for(auto it = oMovie.begin();it!=oMovie.end();++it){
        std::cout<<it.key()<<" "<<it.value()<<std::endl;
    }


    return 0;
}

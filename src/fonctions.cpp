//
// Created by Babin on 3/18/2026.
//

#include "fonctions.h"

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> nom;
    std::string value = "";
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == delimiter) {
            nom.push_back(value);
            value.clear();
        }
        if (str[i] != delimiter) {
            value += str[i];
        }
    }
    nom.push_back(value);
    return nom;
}

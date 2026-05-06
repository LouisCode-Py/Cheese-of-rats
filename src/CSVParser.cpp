//
// Created by Babin on 3/18/2026.
//

#include "CSVParser.h"
#include "fonctions.h"

CSVParser::CSVParser(char delimiter, bool readColumnNames) {
    _delimiter = delimiter;
    _readsColumnNames = readColumnNames;
}

char CSVParser::getDelimiter() const {
    return _delimiter;
}

void CSVParser::setDelimiter(char delimiter) {
    _delimiter = delimiter;
}

bool CSVParser::readsColumnNames() const {
    return _readsColumnNames;
}

void CSVParser::setReadsColumnNames(bool readsColumnNames) {
    _readsColumnNames = readsColumnNames;
}

const std::vector<std::vector<std::string> > &CSVParser::getData() const {
    return _data;
}

const std::vector<std::string> &CSVParser::getColumnNames() const {
    return _columnNames;
}

void CSVParser::parse(std::istream &in) {
    std::string wholeData;
    _data.clear();
    _columnNames.clear();
    std::vector<std::string> whole;
    while (std::getline(in, wholeData)) {
        if (_readsColumnNames && _columnNames.size() == 0) {
            whole = split(wholeData,_delimiter);
            for (size_t i = 0; i < whole.size(); i++) {
                _columnNames.push_back(whole[i]);
            }
            _readsColumnNames = false;
        } else {
            whole = split(wholeData,_delimiter);
            _data.push_back(whole);
        }
    }
}

int CSVParser::getColumnIndex(const std::string &columnName) const {
    for (size_t i = 0; i < _columnNames.size(); i++) {
        if (_columnNames[i] == columnName) {
            int result = i;
            return result;
        }
    }
    throw std::invalid_argument("Le nom de la colonne est invalide");
}

const std::vector<std::string> &CSVParser::getRow(size_t index) const {
    if (index >= _data.size()) {
        throw std::out_of_range("La rangée est invalide");
    }
    return _data[index];
}

const std::string &CSVParser::getString(size_t row, size_t column) const {
    const std::vector<std::string> &rowSize = this->getRow(row);

    if (rowSize.size() <= column) {
        throw std::invalid_argument("L'index de la colonne est invalide");
    }
    return rowSize[column];
}

const std::string &CSVParser::getString(size_t row, const std::string &columnName) const {
    const std::vector<std::string> &result = this->getRow(row);
    size_t index = getColumnIndex(columnName);
    return result[index];
}

int CSVParser::getInt(size_t row, size_t column) const {
    int result = std::stoi(getString(row,column));
    return result;
}

int CSVParser::getInt(size_t row, const std::string &columnName) const {
    int result = std::stoi(getString(row,columnName));
    return result;
}

double CSVParser::getDouble(size_t row, size_t column) const {
    double result = std::stod(getString(row,column));
    return result;
}

double CSVParser::getDouble(size_t row, const std::string &columnName) const {
    double result = std::stod(getString(row,columnName));
    return result;
}

size_t CSVParser::getNumRows() const {
    return _data.size();
}

size_t CSVParser::getNumColumns() const {
    return _columnNames.size();
}

#include <iostream>
#include <string>

bool Verification(const std::string& message) {
    for (const char& character : message) {
        if (character != '0' && character != '1')
            return 0;
    }
    return 1;
}

std::string GeneratePolinom(std::string generatorPolinom) {
    if (generatorPolinom == "")
        return "";

    int k = 0, i, ok = 0;
    std::string expression = "";

    while (generatorPolinom[k] == '0' && k < generatorPolinom.size()) {
        k++;
        ok = 1;
    }
    generatorPolinom.erase(0, k);

    if (ok)
        std::cout << "\nThe expression after erasing the first zeroes if they exist: " << generatorPolinom << '.'<< std::endl;

    bool firstTerm = true;

    for (i = 0; i < generatorPolinom.size(); i++) {
        if (generatorPolinom[i] == '1') {
            if (!firstTerm) {
                expression += " + ";
            }

            int exponent = generatorPolinom.size() - 1 - i;

            if (exponent == 0) {
                expression += "1";
            }
            else {
                expression += "X^" + std::to_string(exponent);
            }

            firstTerm = false;
        }
    }

    return expression;
}

int GradePolinom(const std::string& generatorPolinom) {
    return generatorPolinom.size() - 1;
}

std::string ExtindedPolinom(const std::string& message, const std::string& generatorPolinom) {
    std::string extindedPolinom = message;
    int i;

    for (i = 0; i < GradePolinom(generatorPolinom); i++) {
        extindedPolinom += '0';
    }

    return extindedPolinom;
}

int XOR(const char& bit1, const char& bit2) {
    return bit1 != bit2;
}

std::string DetermineRest(std::string extindedPolinom, const std::string& generatorPolinom) {
    int i, k = 0;
    std::string rest = extindedPolinom;

    while (rest.size() >= generatorPolinom.size()) {
        extindedPolinom = rest;
        std::cout << std::endl << extindedPolinom << std::endl;
        std::cout << generatorPolinom << std::endl;
        std::cout << std::string(20, '-') << std::endl;

        for (i = 0;i < generatorPolinom.size();i++)
            rest[i] = XOR(extindedPolinom[i], generatorPolinom[i]) + '0';

        std::cout << rest << std::endl;

        k = 0;
        while (k < rest.size() && rest[k] == '0')
            k++;

        rest.erase(0, k);
    }

    std::cout << rest << std::endl;
    return rest;
}

int main() {
    std::string message, generatorPolinom, expression, extindedPolinom, rest;
    std::cout << "Please introduce the message: ";
    std::cin >> message;

    if (!Verification(message) || message == "") {
        while (!Verification(message) || message == "") {
            std::cout << "\nPlease introduce a valid message: ";
            std::cin >> message;
        }
    } 

    std::cout << "\nThe expression is valid.\n";

    std::cout << "\nPlease introduce the coeficients of the polinom: ";
    std::cin >> generatorPolinom;

    if (!Verification(generatorPolinom) || generatorPolinom == "") {
        while (!Verification(generatorPolinom) || generatorPolinom == "") {
            std::cout << "\nPlease introduce a valid coeficients: ";
            std::cin >> message;
        }
    }

    std::cout << "\nThe expression is valid.\n";

    expression = GeneratePolinom(generatorPolinom);
    std::cout << "\nThe polinom is: " << expression << '.' << std::endl;

    if (message.size() < generatorPolinom.size()) {
        std::cout << "The message is shorter than the expression.";
        return 0;
    }

    extindedPolinom = ExtindedPolinom(message, generatorPolinom);
    std::cout << "The extinded polinom is: " << extindedPolinom << '.' << std::endl;

    rest = DetermineRest(extindedPolinom, generatorPolinom);
    if (rest == "")
        std::cout << "\nThe rest is null.";
    else std::cout << "\nThe rest is: " << rest << '.';
    return 0;
}

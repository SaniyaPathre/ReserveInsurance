#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

struct Assumptions {
    int Age_Entry;
    int Pol_Term_Y;
    double Init_SA;
    double Init_Prem;
    double V_Int_PC_Y;
    double V_Init_Exp_Prem_PC;
    double V_Re_Exp_Prem_PC;
    double V_Init_Exp_PP;
    double V_Re_Exp_PP;
    double GSV_PC;
    double V_Lapse_Mult_PC;
    double V_Mort_Mult_PC;
    int Prem_Freq;
};

Assumptions readAssumptions(const std::string &filename) {
    std::ifstream file(filename);
    Assumptions assumptions;
    if (file.is_open()) {
        file >> assumptions.Age_Entry >> assumptions.Pol_Term_Y
             >> assumptions.Init_SA >> assumptions.Init_Prem
             >> assumptions.V_Int_PC_Y >> assumptions.V_Init_Exp_Prem_PC
             >> assumptions.V_Re_Exp_Prem_PC >> assumptions.V_Init_Exp_PP
             >> assumptions.V_Re_Exp_PP >> assumptions.GSV_PC
             >> assumptions.V_Lapse_Mult_PC >> assumptions.V_Mort_Mult_PC
             >> assumptions.Prem_Freq;
    }
    file.close();
    return assumptions;
}

double calculateReserve(const Assumptions &assumptions) {
   
    double yearlyInterest = assumptions.V_Int_PC_Y / 100.0;
    double reserve = 0.0;

    for (int year = 1; year <= assumptions.Pol_Term_Y; ++year) {
        double annualPremium = assumptions.Init_Prem * assumptions.Prem_Freq;
        reserve += (annualPremium - (assumptions.V_Init_Exp_PP + assumptions.V_Re_Exp_PP)) *
                   (1.0 + yearlyInterest);
    }
    return reserve;
}

int main() {
    // Input assumption file
    std::string inputFile = "Assumptions.csv";

    // Modify this to select the correct file path for each version
    //std::string inputFile = "../Assumptions1/Assumptions.csv";  // Adjust for Program1, Program2, Program3

    // Read assumptions
    Assumptions assumptions = readAssumptions(inputFile);

    // Perform reserve calculation
    double reserve = calculateReserve(assumptions);

    // Output the results
    std::cout << "Insurance Reserve Value: " << std::fixed << std::setprecision(2) << reserve << std::endl;

    // Save output to file
    std::ofstream outFile("Reserve_Output.txt");
    outFile << "Insurance Reserve Value: " << std::fixed << std::setprecision(2) << reserve << std::endl;
    outFile.close();

    return 0;
}

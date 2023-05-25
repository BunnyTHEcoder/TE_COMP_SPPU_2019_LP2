#include <iostream>
#include <unordered_map>
using namespace std;

// Define the knowledge base
unordered_map<string, unordered_map<string, double>> knowledge_base = {
    {"APPLE", {{"earnings_growth", 0.05}, {"revenue_growth", 0.02}, {"market_cap", 200000000000}, {"dividend_yield", 0.01}}},
    {"GOOGLE", {{"earnings_growth", 0.08}, {"revenue_growth", 0.05}, {"market_cap", 1200000000000}, {"dividend_yield", 0.00}}},
    {"AMAZON", {{"earnings_growth", 0.06}, {"revenue_growth", 0.10}, {"market_cap", 1500000000000}, {"dividend_yield", 0.00}}}
};

// Define the inference engine
void evaluateStock(const string& stock) {
    int score = 0;
    if (knowledge_base[stock]["earnings_growth"] > 0.05)
        score += 1;
    if (knowledge_base[stock]["revenue_growth"] > 0.05)
        score += 1;
    if (knowledge_base[stock]["market_cap"] > 1000000000000)
        score += 1;
    if (knowledge_base[stock]["dividend_yield"] > 0.01)
        score -= 1;

    if (score >= 3) {
        cout << "Score = " << score << endl;
        cout << stock << " is a good buy (based on rule-based evaluation)." << endl;
    } else if (score >= 2 && score < 3) {
        cout << "Score = " << score << endl;
        cout << stock << " is good to hold (based on rule-based evaluation)." << endl;
    } else {
        cout << "Score = " << score << endl;
        cout << stock << " is not a good buy (based on rule-based evaluation)." << endl;
    }
}

int main() {
    while (true) {
        // Get user input
        string stock_symbol;
        cout << "Enter a stock symbol: ";
        cin >> stock_symbol;

        // Test the system
        evaluateStock(stock_symbol);

        string x;
        cout << "Do you want to continue? (Y or N): ";
        cin >> x;
        if (x == "Y" || x == "y")
            continue;
        else if (x == "N" || x == "n")
            break;
        else
            cout << "Please enter valid input." << endl;
    }

    return 0;
}

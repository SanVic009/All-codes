#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Function to generate HTML for the bill with internal CSS
void generateHTMLBill(const string &filename, const vector<pair<string, pair<double, int>>> &purchasedItems)
{
    ofstream htmlFile(filename);

    // Check if the file opened successfully
    if (!htmlFile.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    // Calculate total bill and tax
    double totalBeforeTax = 0;
    for (const auto &item : purchasedItems)
    {
        totalBeforeTax += item.second.first * item.second.second;
    }
    double tax = totalBeforeTax * 0.07; // 7% tax
    double totalAfterTax = totalBeforeTax + tax;

    // Writing HTML content with internal CSS
    htmlFile << "<!DOCTYPE html>\n<html>\n<head>\n";
    htmlFile << "<style>\n"
             << "body {font-family: Arial, sans-serif;}\n"
             << ".bill-container {max-width: 600px; margin: auto; padding: 20px; border: 1px solid #ccc;}\n"
             << "h1 {text-align: center;}\n"
             << "table {width: 100%; border-collapse: collapse; margin-bottom: 20px;}\n"
             << "th, td {border: 1px solid #ccc; padding: 10px; text-align: left;}\n"
             << "th {background-color: #f2f2f2;}\n"
             << ".total {font-weight: bold;}\n"
             << ".footer {text-align: center; padding: 10px;}\n"
             << "</style>\n";
    htmlFile << "</head>\n<body>\n";

    htmlFile << "<div class='bill-container'>\n";
    htmlFile << "<h1>Supermarket Bill</h1>\n";
    htmlFile << "<table>\n";
    htmlFile << "<tr><th>Product</th><th>Price (Rs.)</th><th>Quantity</th><th>Total (Rs.)</th></tr>\n";

    // Loop through purchased items to add them to the bill
    for (const auto &item : purchasedItems)
    {
        double totalItemPrice = item.second.first * item.second.second;
        htmlFile << "<tr><td>" << item.first << "</td><td>" << item.second.first << "</td><td>" << item.second.second
                 << "</td><td>" << totalItemPrice << "</td></tr>\n";
    }

    // Display total and tax
    htmlFile << "<tr><td colspan='3' class='total'>Total Before Tax</td><td class='total'>" << totalBeforeTax << "</td></tr>\n";
    htmlFile << "<tr><td colspan='3' class='total'>Tax (7%)</td><td class='total'>" << tax << "</td></tr>\n";
    htmlFile << "<tr><td colspan='3' class='total'>Total After Tax</td><td class='total'>" << totalAfterTax << "</td></tr>\n";
    htmlFile << "</table>\n";

    htmlFile << "<div class='footer'>Thank you for shopping with us!</div>\n";
    htmlFile << "</div>\n";

    htmlFile << "</body>\n</html>";
    htmlFile.close();
}

// Function to open the HTML file in the default browser
void openHTMLFile(const string &filename)
{
#if defined(_WIN32) || defined(_WIN64)
    system(("start " + filename).c_str());
#elif defined(__APPLE__)
    system(("open " + filename).c_str());
#else
    system(("xdg-open " + filename).c_str());
#endif
}

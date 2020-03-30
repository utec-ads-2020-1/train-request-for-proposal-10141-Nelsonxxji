#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int RFPNumber = 1;
    string line, bestProp;
    istringstream ss;

    while (getline(cin, line))
    {
        int n, p, reqMet, propNumber = 1;
        string req, prop;
        float compliance, price, maxCompliance = 0, minPrice = numeric_limits<float>::max();

        ss.str(line);
        ss >> n >> p;
        ss.clear();

        if (n == 0 || p == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
        }
        while (propNumber <= p)
        {
            getline(cin, line);
            ss.str(line);
            ss >> prop;
            ss.clear();

            getline(cin, line);
            ss.str(line);
            ss >> price >> reqMet;
            ss.clear();

            for (int j = 0; j < reqMet; j++)
            {
                getline(cin, line);
            }
            compliance = float(reqMet) / (float)n;

            if (compliance > maxCompliance)
            {
                maxCompliance = compliance;
                minPrice = price;
                bestProp = prop;
            }
            else if (compliance == maxCompliance)
            {
                if (price < minPrice)
                {
                    minPrice = price;
                    bestProp = prop;
                }
            }
            propNumber++;
        }
        cout << "RFP #" << RFPNumber << endl
             << bestProp << endl;
        RFPNumber++;
    }
    return EXIT_SUCCESS;
}

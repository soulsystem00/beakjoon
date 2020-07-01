#include <iostream>

using namespace std;

int main()
{
    int Cardcnt;
    int MAXtotal;
    cin >> Cardcnt >> MAXtotal;

    int* card = new int[Cardcnt];

    for (int i = 0; i < Cardcnt; i++)
    {
        cin >> card[i];
    }

    int MAXcombi = Cardcnt * (Cardcnt - 1) * (Cardcnt - 2) / 6;
    int cnt = 0;
    int* combi = new int[MAXcombi];
    int MAXvalue = 0;
    for (int i = 0; i < MAXcombi; i++)
    {
        combi[i] = 0;
    }

    for (int i = 0; i < Cardcnt; i++)
    {
        for (int j = i + 1; j < Cardcnt; j++)
        {
            for (int k = j + 1; k < Cardcnt; k++)
            {
                combi[cnt] = card[i] + card[j] + card[k];
                
                cnt++;
            }
        }
    }

    for (int i = MAXcombi-1; i >= 0; i--)
    {
        if (combi[i] <= MAXtotal && combi[i] != 0 && combi[i]>MAXvalue)
        {
            MAXvalue = combi[i];
        }
    }

    cout << MAXvalue << endl;
}


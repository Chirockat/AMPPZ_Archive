// na pewno trzeba szybkie potegowanie modulo...

#include<iostream>
#include<cstring>
#include<bitset>

using namespace std;

string intToBinaryBitset(int x) {
    return bitset<30>(x).to_string();
}

int main() {
    int32_t n;
    cin >> n;

    int64_t a, b, output;

    string bin_b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        // zamieniamy b na zapis binarny, jest biblioteka sama to robiaca to korzystamy. Max 30 znakow to zajmie
        bin_b = intToBinaryBitset(b);

        // szybkie potegowanie algorytm (nie, nie wiem czemu to tak działa)

        output = 1;

        while (bin_b != "0" && bin_b.length() > 0) {
            if (bin_b[bin_b.length() - 1] == '1') {
                output = (output * a) % 1000000007;
            }
            a = (a * a) % 1000000007;
            // to jest dzielenie b przez 2
            bin_b.pop_back();
        }

        cout << output << endl;

    }
}
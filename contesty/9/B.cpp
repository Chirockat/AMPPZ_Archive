#include <iostream>
#include <map>

using namespace std;

#define print(var) cout << #var <<": " << var << endl;

int main () {
    int32_t t;
    cin >> t;

    

    int32_t n;
    int32_t student;

    
    
    


    for (int i = 0; i < t; i++) {

        map <int32_t, int32_t> mapa;

        int32_t most_common_number = 0;
        int32_t max_count = 0;;

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> student;
            // if (mapa.find(student)== mapa.end()) {
            //     mapa[student] = 1;
            // }
            // else {
            //     mapa[student]++;
            // }
            mapa[student]++;        // ta jedna linijka robi to samo co to wszystko wyzej
            if (mapa[student] > max_count) {
                max_count = mapa[student];
                most_common_number = student;
            }
        }

        int32_t t1_count = 0;
        int32_t t2_count = 0;

        t2_count = max_count;
        mapa.erase(most_common_number);

        t1_count = mapa.size();

        print(t1_count);
        print(t2_count);


    }

}
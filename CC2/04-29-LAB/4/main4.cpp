/*4. Dado un vector de char*, retorne un nuevo vector conteniendo las cadenas de caracteres que contiene al menos
un d ́ıgito num ́erico, si no existe ninguno, retornar un vector vac ́ıo. (Se incluye un conjunto de palabras de
entrada para probar su algoritmo)*/
#include <iostream>
#include <vector>
using namespace std;

vector<char*> fun4(vector<char*> words, vector<int> sizes) {
    vector<char*> result;
    for (int i=0;i<words.size(); i++) {
        for (int j=0; j<sizes[i]; j++) {
            switch (words[i][j]) {
                case '1':
                    result.push_back(words[i]);
                    break;
                case '2':
                    result.push_back(words[i]);
                    break;
                case '3':
                    result.push_back(words[i]);
                    break;
                case '4':
                    result.push_back(words[i]);
                    break;
                case '5':
                    result.push_back(words[i]);
                    break;
                case '6':
                    result.push_back(words[i]);
                    break;
               case '7':
                    result.push_back(words[i]);
                    break;
               case '8':
                    result.push_back(words[i]);
                    break;
               case '9':
                    result.push_back(words[i]);
                    break;
               case '0':
                    result.push_back(words[i]);
                    break;
            }
        }
    }

    return result;
}
int main() {
    vector<char*> words = {"green23","black","blue42","yellow7","purple99","orange123","pink8","brown56",
"silver100","gold777","teal2021","maroon","violet999","lime25","indigo1234",
"coral567","turquoise333","magenta","beige123456","navy7777","crimson12345",
"ivory987","lavender","chartreuse456","salmon789","khaki1234","azure567",
"olive111","fuchsia9876","plum","cyan654","tan","orchid234","aquamarine7890",
"peru123","tomato567","thistle1234","bisque987","wheat","seashell789","papayaWhip123",
"linen","mistyRose1234","honeydew","mintCream456","antiqueWhite789",
"oldLace","cornsilk567","snow1234","floralWhite789"};
    vector<int> sizes;
    for (int i=0;i<words.size(); i++) {
        sizes.push_back(sizeof(words[i])/sizeof(char));
    }
    vector<char*> result = fun4(words, sizes);

    for (int i=0;i<result.size();i++) {
        cout<<result[i]<<endl;
    }


}

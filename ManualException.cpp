#include <iostream>
using namespace std;

int main()
{
    //mambuat isi dari try untuk pengujian error
    try
    {
        cout << "Selamat belajar di prodi TI UMY" << endl;
        //throw 0.5; //melemparkan sebuah integar maka
        cout << "Pernyataan tidak akan ditampilkan" << endl;
    }
    //kondisi jika throw yang bertipe data integar
    catch (int a)
    {
        cout << "Pengecualian akan di eksekusi" << endl;
    }
    
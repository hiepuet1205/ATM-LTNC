#include "function.h"
#include "main.h"
#include "input.h"
#include "output.h"

using namespace std;

int id;
string pass;

int so_to_tung_menh_gia[9];
int so_tien_atm;

int login_thanh_cong = 0;

int tuy_chon;
int temp;

vector<account> list_account;

int main(){
    nhap_account();
    nhap_so_luong_tien();
    tien_atm();

    login();

    menu( list_account[temp]);

    return 0;
}

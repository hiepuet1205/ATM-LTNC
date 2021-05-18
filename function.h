#ifndef function__H_
#define function__H_

#include <string>
#include <vector>

using namespace std;

struct account{
    int id;
    string pass;
    int pass_2;
    int so_lan_sai_pass;
    int so_tien;
    bool khoa_tk;

    account(int id_, string pass_, int pass_2_, int so_lan_sai_pass_, int so_tien_, bool khoa_tk_){
        id = id_;
        pass = pass_;
        pass_2 = pass_2_;
        so_lan_sai_pass = so_lan_sai_pass_;
        so_tien = so_tien_;
        khoa_tk = khoa_tk_;
    }

    account(){}
};

bool check_pass(string pass, string pass_temp);
bool check_khoa_tk(account a);
bool check_tien_rut(int so_tien_rut, int so_tien_atm);

void login();
void xu_ly_login_tk();

void menu(account& a);

void check_tien(account a);

void xu_ly_rut_tien(account& a, int so_tien_rut);
void rut_tien(account& a);

void xu_ly_gui_tien(account& a, int& so_tien_gui);
void gui_tien(account& a);

void xu_ly_chuyen_tien(account& nguoi_gui, account& nguoi_nhan);
void chuyen_tien(account& a);

void kiem_tra_lich_su(account& a);

void doi_pass(account& a);

#endif // function__H_

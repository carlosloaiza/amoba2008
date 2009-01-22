/*
 * window.cpp
 *
 *  Created on: 2009.01.09.
 *      Author: Karacs Anita
 */

#include <iostream>
#include <fstream>
#include "gtkmm.h"
#include "window.hpp"

ifstream userFile;

myWindow::myWindow():
	myTable(7,5,true),
	myTable2(7,5,true),
	myTable3(7,5,true),
	sTable(1,1,true),
	close("Kilep"),
	next("Tovabb >>>"),
	ok("OK"),
	testOk("OK"),
	enter("Belepes >>>"),
	login("Bejelentkezes"),
	new_user("Uj felhasznalo")
{
	good=0;
	bad=0;
	set_title("Angol szogyakorlo");
	set_default_size(600,350);
	set_border_width(40);
	setColor(37000,35000,5000);
	modify_bg(STATE_NORMAL,c);

	//myLabel.modify_text(STATE_NORMAL,c);
	icon.add_pixlabel("angol.jpg","ANGOL TUDASTESZTELO");
	icon.set_sensitive(false);
	myLabel.set_alignment(ALIGN_CENTER); //NEM JO, KÖZÉPRE KELL IGAZÍTANI
	myLabel.set_text("Udv a szogyakorloban!\n"
			"Kattints arra az opciora, amit szeretnel (akkor is, ha ki van jelolve).");
	myGroup=login.get_group();
	new_user.set_group(myGroup);
	login.signal_pressed().connect(sigc::mem_fun(*this,&myWindow::loginPressed));
	login.signal_clicked().connect(sigc::mem_fun(*this,&myWindow::nextSensitive));
	new_user.signal_pressed().connect(sigc::mem_fun(*this,&myWindow::new_userPressed));
	new_user.signal_clicked().connect(sigc::mem_fun(*this,&myWindow::nextSensitive));
	//close.signal_clicked().connect(sigc::mem_fun(*this,&myWindow::closeClicked));
	next.signal_clicked().connect(sigc::mem_fun(*this,&myWindow::nextClicked));
	next.set_sensitive(false);
	myTable.set_row_spacings(5);
	myTable.set_col_spacings(5);
	myTable.attach(icon,1,4,0,1);
	myTable.attach(myLabel,0,5,1,3);
	myTable.attach(login,2,3,3,4);
	myTable.attach(new_user,2,3,4,5);
	//myTable.attach(close,1,2,6,7);
	myTable.attach(next,2,3,6,7);

	add(myTable);
	show_all_children();
}

void myWindow::closeClicked(){
	hide();
}

void myWindow::nextSensitive(){
	next.set_sensitive(true);
}

void myWindow::nextClicked(){
	remove();

	userLabel.set_text("Felhasznalonev:");
	userLabel.set_alignment(ALIGN_LEFT);
	passwordLabel.set_text("Jelszo:");
	passwordLabel.set_alignment(ALIGN_LEFT);
	icon2.add_pixlabel("angol.jpg","ANGOL TUDASTESZTELO");
	icon2.set_sensitive(false);
	ok.signal_clicked().connect(sigc::mem_fun(*this,&myWindow::okClicked));
	enter.set_sensitive(false);
	myFrame.add(myLabel2);
	myTable2.set_row_spacings(5);
	myTable2.set_col_spacings(5);
	myTable2.attach(icon2,1,4,0,1);
	myTable2.attach(title,1,4,1,2);
	myTable2.attach(userLabel,1,2,2,3);
	myTable2.attach(passwordLabel,1,2,3,4);
	myTable2.attach(userEntry,2,4,2,3);
	myTable2.attach(passwordEntry,2,4,3,4);
	myTable2.attach(ok,1,2,5,6);
	myTable2.attach(enter,3,4,5,6);
	myTable2.attach(myFrame,0,5,6,7);

	add(myTable2);
	show_all_children();
}

void myWindow::loginPressed(){
	title.set_text("BEJELENTKEZES");
	whatPressed="login";
}

void myWindow::new_userPressed(){
	title.set_text("REGISZTRACIO");
	whatPressed="new";
	langLabel.set_text("Nyelv:");
	langLabel.set_alignment(ALIGN_LEFT);
	myCombo.append_text("Angol-magyar");
	myCombo.append_text("Magyar-angol");
	myCombo.set_active_text("Angol-magyar");
	myTable2.attach(langLabel,1,2,4,5);
	myTable2.attach(myCombo,2,4,4,5);
	language=myCombo.get_active_text();
}

void myWindow::okClicked(){
	user=userEntry.get_text();
	string fileOpen=user+".usr";
	//ifstream f(user.c_str());

	userFile.open(fileOpen.c_str());
	if(whatPressed=="login"){
		if(userFile==NULL){
			myLabel2.set_text("Nem letezo felhasznalo.");
		}else{
			if(!passwordCheck(userFile)){
				myLabel2.set_text("Rossz jelszo. Adja meg helyesen a jelszot!");
			}else{
				ifstream dic((user+".dic").c_str()); //dic=dictionary saját szótár, gyakorisággal!
				while(!dic.eof()){
					dictionary.push_back(loading(dic));
				}
				dic.close();

				getline(userFile,language,'#');
				myLabel2.set_text("Kattintson a belepes gombra!");
				enter.set_sensitive(true);
			}
		}
	}else{
		if(whatPressed=="new"){
			if(userFile!=NULL){
				myLabel2.set_text("Mar letezo felhasznalo. Adjon meg uj nevet!");
			}else{
				ofstream o(fileOpen.c_str());
				for(int i=0;i<passwordEntry.get_text_length();i++){
					o<<(char)((int) (passwordEntry.get_text().at(i))+50);
				}
				o<<"#"<<myCombo.get_active_text();
				o.close();

				ifstream dic1("szotar.txt"); //dic=dictionary központi szótár!
				while(!dic1.eof()){
					dictionary.push_back(loading(dic1));
				}
				dic1.close();

				ofstream dic2((user+".dic").c_str());
				dic2.close();

				myLabel2.set_text("Sikeres regisztracio! Kattintson a belepes gombra!");
				enter.set_sensitive(true);
			}
		}
	}
	userFile.close();
	enter.signal_clicked().connect(sigc::mem_fun(*this,&myWindow::enterClicked));
	show_all_children();
}

void myWindow::enterClicked(){
	remove();

	icon3.add_pixlabel("angol.jpg","ANGOL TUDASTESZTELO");
	icon3.set_sensitive(false);
	myFrame2.add(myScrolledWindow);
	sTable.attach(testLabel2,0,1,0,1);
	myScrolledWindow.add(sTable);
	myScrolledWindow.set_policy(POLICY_AUTOMATIC,POLICY_AUTOMATIC);
	testLabel1.set_alignment(ALIGN_LEFT);
	myTable3.set_row_spacings(5);
	myTable3.set_col_spacings(5);
	myTable3.attach(icon3,1,4,0,1);
	myTable3.attach(myFrame2,0,5,1,5);
	myTable3.attach(testLabel1,0,5,5,6);
	myTable3.attach(testEntry,0,4,6,7);
	myTable3.attach(testOk,4,5,6,7);
	test(userFile);

	add(myTable3);
	show_all_children();
}

void myWindow::test(ifstream &t){
	if(whatPressed=="login"){
		sort();
	}
	cout<<"ccc"<<language;
	if(language=="Angol-magyar"){ // elég az egyik logikáját leírni, a másik ua. csak fordítva
		testOk.signal_clicked().connect(sigc::mem_fun(*this,&myWindow::testOkClicked));
		for(int i=0;i<25;i++){		//itt a gond!
			testLabel1.set_text(dictionary.at(i).eng+":");

			if(dictionary.at(i).hu.find(testEntry.get_text())!=dictionary.at(i).hu.npos){
				good++;
				testLabel2.set_text(testLabel2.get_text()+"\tJo megoldas");
				dictionary.at(i).freq--;
			}else{
				bad++;
				testLabel2.set_text(testLabel2.get_text()+"\tRossz megoldas");
				dictionary.at(i).freq+=3;
			}
		}

		std::remove((user+".dic").c_str());
		ofstream dic3((user+".dic").c_str());
		for(int i=0;i<dictionary.size();i++){
			stringstream ss;
			ss<<dictionary.at(i).freq;
			dic3<<ss.str()<<"-"<<dictionary.at(i).eng<<"-"<<dictionary.at(i).hu<<endl;
		}
		dic3.close();
	}
	if(language=="Magyar-angol"){

	}
}

void myWindow::testOkClicked(){
	testLabel2.set_text(testLabel2.get_text()+testLabel1.get_text()+"\t"+testEntry.get_text());
}

void myWindow::sort(){
	int j=dictionary.size()-1;
	myWindow::word temp;
	while(j>=0){
		for(int i=0;i<j;i++){
			if(dictionary.at(i).freq<dictionary.at(i+1).freq){
				temp=dictionary.at(i);
				dictionary.at(i)=dictionary.at(i+1);
				dictionary.at(i+1)=temp;
			}
		}
		j--;
	}
}

myWindow::word myWindow::loading(ifstream &t){
	word e;
	string _freq;
	if(whatPressed=="new"){
		e.freq=6;
		getline(t,e.eng,'-');
		getline(t,e.hu);
	}else{
		getline(t,_freq,'-');
		e.freq=atoi(_freq.c_str());
		getline(t,e.eng,'-');
		getline(t,e.hu);
	}
	if (!t.good()) return e;
	return e;
}

bool myWindow::passwordCheck(ifstream &l){
	string _password,pw;
	getline(l,pw,'#');
	for(int i=0;i<pw.length();i++){
		_password.push_back((char)((int) pw.at(i)-50));
	}
	if(_password==passwordEntry.get_text()){
		return true;
	}else return false;
}

void myWindow::setColor(int r,int g,int b){
	c.set_red(r);
	c.set_green(g);
	c.set_blue(b);
}

#include <iostream>
#include <fstream>
#include "ip.h"
using namespace std;

short checksum(struct ip* datagram){
	long sum = 0;
	sum += datagram->ip_verlen;
	sum += datagram->ip_tos;
	sum += datagram->ip_len;
	sum += datagram->ip_id;
	sum += datagram->ip_fragoff;
	sum += datagram->ip_ttl;
	sum += datagram->ip_proto;
	sum += datagram->ip_src;
	sum += datagram->ip_dst;
	sum += datagram->ip_data[1];
	return (sum & 0xFFFFFFFF);
}

int main(){
	ip testDatagram;
	testDatagram.ip_verlen = 0x04+0x05;
	testDatagram.ip_tos = 0x00;
	testDatagram.ip_len = 0x0014; //20
	testDatagram.ip_id = 0x0000;
	testDatagram.ip_fragoff = 0x0000;
	testDatagram.ip_ttl = 0xff;
	testDatagram.ip_proto = IPT_TCP; //0x06
	testDatagram.ip_src = 0xC0A80101; //192.168.1.1
	testDatagram.ip_dst = 0x08080808; //8.8.8.8
	testDatagram.ip_data[1] = 0x00; // no data
	ip* passThis = &testDatagram;
	testDatagram.ip_cksum = checksum(passThis);
	
	ofstream outputFile("hw5output.txt");
	outputFile<<(u_short)testDatagram.ip_verlen<<"\n";
	outputFile<<(u_short)testDatagram.ip_tos<<"\n";
	outputFile<<testDatagram.ip_len<<"\n";
	outputFile<<testDatagram.ip_id<<"\n";
	outputFile<<testDatagram.ip_fragoff<<"\n";
	outputFile<<(u_short)testDatagram.ip_ttl<<"\n";
	outputFile<<(u_short)testDatagram.ip_proto<<"\n";
	outputFile<<testDatagram.ip_src<<"\n";
	outputFile<<testDatagram.ip_dst<<"\n";
	outputFile<<(u_short)testDatagram.ip_data[1]<<"\n";
	outputFile<<testDatagram.ip_cksum<<"\n";
	outputFile.close();
	
	ifstream inputFile("hw5output.txt");
	string temp;
	getline(inputFile, temp);
	cout<<"ip_verlen="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_tos="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_len="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_id="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_fragoff="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_ttl="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_proto="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_src="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_dst="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_data="<<temp<<endl;
	getline(inputFile, temp);
	cout<<"ip_cksum="<<temp<<endl;
	inputFile.close();

	return 1;
}

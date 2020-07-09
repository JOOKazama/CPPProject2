#include "pch.h"
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class PC
{
	private:

		int id;
		string brand;
		string model;
		string cpu_maker;
		string cpu_model;
		float hz;
		int cores;
		int ram;
		float price;
		string status;

	public:

		void set_id(int id1) { this->id=id1; }
		void set_brand(string brand1) { this->brand=brand1; }
		void set_model(string model1) { this->model=model1; }
		void set_cpu_maker(string cpu_maker) { this->cpu_maker=cpu_maker; }
		void set_cpu_model(string cpu_model) { this->cpu_model=cpu_model; }
		void set_hz(float hz) { this->hz=hz; }
		void set_cores(int cores) { this->cores=cores; }
		void set_ram(int ram) { this->ram=ram; }
		void set_price(float price) { this->price=price; }
		void set_status(string status) { this->status=status; }

		int get_id() { return id; }
		string get_brand() { return brand; }
		string get_model() { return model; }
		string get_cpu_maker() { return cpu_maker; }
		string get_cpu_model() { return cpu_model; }
		float get_hz() { return hz; }
		int get_cores() { return cores; }
		int get_ram() { return ram; }
		float get_price() { return price; }
		string get_status() { return status; }

		bool operator ==(const PC& pc)
		{
			if(brand==pc.brand && model==pc.model && cpu_maker==pc.cpu_maker && cpu_model==pc.cpu_model && hz==pc.hz && cores==pc.cores && ram==pc.ram && price==pc.price && status==pc.status)
			{ return true; }
			return false;
		}

		static bool compare_id(const PC& pc, const PC& pc1) { return pc.id<pc1.id; }
		static bool compare_price(const PC& pc, const PC& pc1) { return pc.price<pc1.price; }
		static bool compare_cpu_model(const PC& pc, const PC& pc1) { return pc.cpu_model<pc1.cpu_model; }
	};

void set_PC(PC &pc)
{
	int id, cores, ram;
	string brand, model, cpu_maker, cpu_model, status;
	float hz, price;

	cout<<"Enter ID."<<endl;
	cin>>id;
	pc.set_id(id);

	cout<<"Enter brand."<<endl;
	cin>>brand;
	pc.set_brand(brand);

	cout<<"Enter model."<<endl;
	cin>>model;
	pc.set_model(model);

	cout<<"Enter CPU maker."<<endl;
	cin>>cpu_maker;
	pc.set_cpu_maker(cpu_maker);

	cout<<"Enter CPU model."<<endl;
	cin>>cpu_model;
	pc.set_cpu_model(cpu_model);

	cout<<"Enter CPU Hz."<<endl;
	cin>>hz;
	pc.set_hz(hz);

	cout<<"Enter CPU Cores."<<endl;
	cin>>cores;
	pc.set_cores(cores);

	cout<<"Enter RAM."<<endl;
	cin>>ram;
	pc.set_ram(ram);

	cout<<"Enter Price."<<endl;
	cin>>price;
	pc.set_price(price);

	cout<<"Enter Status(to be sold or sold)."<<endl;
	cin>>status;
	pc.set_status(status);
}

void save_to_file(PC pc, string file_name)
{
	ofstream my_file(file_name.c_str(), ios_base::app);
	my_file<<pc.get_id()<<" ";
	my_file<<pc.get_brand()<<" ";
	my_file<<pc.get_model()<<" ";
	my_file<<pc.get_cpu_maker()<<" ";
	my_file<<pc.get_cpu_model()<<" ";
	my_file<<pc.get_hz()<<" ";
	my_file<<pc.get_cores()<<" ";
	my_file<<pc.get_ram()<<" ";
	my_file<<pc.get_price()<< " ";
	my_file<<pc.get_status()<<endl;
}

void ask_for_save_to_file(PC pc)
{
	int choice;
	cout<<"1.Do you want to save the info to file? (1 for yes / 2 for no) "<<endl;
	cin>>choice;

	switch(choice)
	{
		case 1: 
		{ 
			save_to_file(pc, "text.txt");
			break; 
		}

		case 2: { break; }
	}
}

void show_all_pcs(vector<PC>&pc)
{
	for(size_t i=0; i<pc.size(); i++)
	{
		cout<<"The ID is: "<<pc[i].get_id()<<endl;
		cout<<"The brand is: "<<pc[i].get_brand()<<endl;
		cout<<"The model is: "<<pc[i].get_model()<<endl;
		cout<<"The CPU maker is: "<<pc[i].get_cpu_maker()<<endl;
		cout<<"The CPU model is: "<<pc[i].get_cpu_model()<<endl;
		cout<<"The Hz are: "<<pc[i].get_hz()<<endl;
		cout<<"The cores are: "<<pc[i].get_cores()<<endl;
		cout<<"The RAM is: "<<pc[i].get_ram()<<endl;
		cout<<"The price is: "<<pc[i].get_price()<<endl;
		cout<<"The status is: "<<pc[i].get_status()<<endl<<endl;
	}
}

int main(void)
{
	vector<PC>pcs;
	int choice, number_of_pcs, choice1, id;

	do
	{
		system("CLS");
		cout<<"1.Add one new PC.\n"
			<<"2.Add several new PCs.\n"
			<<"3.Show all PCs.\n"
			<<"4.Add new data for a PC.\n"
			<<"5.Sell a PC.\n"
			<<"6.Show all PCs for sale in order(ID).\n"
			<<"7.Show all PCs with given CPU and RAM(from the most expensive to the cheapest).\n"
			<<"8.Show all sold PCs in order(CPU model).\n"
			<<"9.Exit \n";

		cin>>choice;
		PC pc;

		switch(choice)
		{
			case 1:
			{
				set_PC(pc);

				if(find(pcs.begin(), pcs.end(), pc)!=pcs.end()) { cout<<"There is already a PC like this!"<<endl; }
				else 
				{ 
					pcs.push_back(pc);
					ask_for_save_to_file(pc);
				}

				break;
			}

			case 2:
			{
				cout<<"How many PCs?"; 
				cin>>number_of_pcs;

				while(number_of_pcs>100)
				{ 
					cout<<"How many PCs?";
					cin>>number_of_pcs;
				}

				for(size_t i=0; i<number_of_pcs; i++)
				{
					PC single;
					set_PC(single);

					if(find(pcs.begin(), pcs.end(), single)!=pcs.end()) { cout<<"There is already a PC like this!"<<endl; }

					else
					{
						pcs.push_back(single); 
						ask_for_save_to_file(single);
						int choice;
						cout<<".Do you want to stop adding? (1 for yes/ 2 for no)"<<endl;
						cin>>choice;

						switch(choice)
						{
							case 1: { i=number_of_pcs; }
							case 2: {}
						}
					}
				}

				break;
			}

			case 3: 
			{ 
				show_all_pcs(pcs);
				
				break;
			}

			case 4:
			{
				cout<<"Enter ID."<<endl;
				cin>>id;

				for(size_t i=0; i<pcs.size(); i++)
				{
					if(id==pcs[i].get_id() && pcs[i].get_status()=="tobesold") { set_PC(pcs[i]); }
					else cout<<"The pc is sold!"<<endl;
				}
				
				break;
			}

			case 5:
			{
				cout<<"Enter ID."<<endl;
				cin>>id;

				for(size_t i=0; i<pcs.size(); i++)
				{
					if(id==pcs[i].get_id() && pcs[i].get_status()=="tobesold") { pcs[i].set_status("sold"); }
					else cout<<"The pc is sold!"<<endl;
				}
				
				break;
			}

			case 6:
			{
				vector<PC>vector_pcs;
				for (size_t i=0; i<pcs.size(); i++)
				{
					if(pcs[i].get_status()=="tobesold")
					{
						vector_pcs.push_back(pcs[i]);
						sort(vector_pcs.begin(), vector_pcs.end(), PC::compare_id);
					}
				}

				show_all_pcs(vector_pcs);
				
				break;
			}

			case 7:
			{
				string cpu_model;
				int ram;
				vector<PC>vector_pcs;

				cout<<"Enter CPU model."<<endl; 
				cin>>cpu_model;
				cout<<"Enter RAM."<<endl; 
				cin>>ram;

				for(size_t i=0; i<pcs.size(); i++)
				{
					if(cpu_model==pcs[i].get_cpu_model() && ram==pcs[i].get_ram())
					{
						vector_pcs.push_back(pcs[i]);
						sort(vector_pcs.begin(), vector_pcs.end(), PC::compare_price);
						reverse(vector_pcs.begin(), vector_pcs.end());
					}
				}

				show_all_pcs(vector_pcs);
				
				break;
			}

			case 8:
			{
				vector<PC>vector_pcs;
				for (size_t i=0; i<pcs.size(); i++)
				{
					if(pcs[i].get_status()=="sold")
					{
						vector_pcs.push_back(pcs[i]);
						sort(vector_pcs.begin(), vector_pcs.end(), PC::compare_cpu_model);
					}
				}

				show_all_pcs(vector_pcs);
				
				break;
			}

			case 9:
				exit(0);
				
				break;
		}

		cout<<"Would you like to return to the menu? 1.Yes 2.No"; 
		cin>>choice1;

	} 
	while(choice1==1);

	system("pause");
}

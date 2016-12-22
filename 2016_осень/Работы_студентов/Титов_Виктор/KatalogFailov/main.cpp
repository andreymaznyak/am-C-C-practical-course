#include <iostream>
#include <vector>

using namespace std;

class BaseNode
{
	string name;

public:
	BaseNode(){}

	BaseNode(string s)
	{
		name = s;
	}

	string getName()
	{
		return name;
	}
};


class File : public BaseNode
{
	string data;
public:
	File() :BaseNode(){}

	File(string s) :BaseNode(s)
	{
	}

	void setText(string text)
	{
		data = text;
	}

	string getText()
	{
		return data;
	}

	void printText()
	{
		cout<<data.c_str();
	}

};

class Folder : public BaseNode
{

	vector<File*> files;
public:
	vector<Folder*> folders;

	Folder() :BaseNode(){}

	Folder(string s) : BaseNode(s)
	{
	}

	void addFolder(string s)
	{
		folders.push_back(new Folder(s));
	}
	void addFile(string s, string text)
	{
		files.push_back(new File(s));
		files[files.size()-1]->setText(text);
	}

	void del()
	{
		for (int i = 0; i < folders.size(); ++i)
			if(folders[i]) folders[i]->del();

		for (int i = 0; i < files.size(); ++i)
			delete files[i];

		files.clear();
		folders.clear();
	}

	int getFolderSize()
	{
		return folders.size();
	}

	void show()
	{
		for (int i = 0; i < folders.size(); ++i)
			cout << folders[i]->getName().c_str() << endl;

		for (int i = 0; i < files.size(); ++i)
			cout << files[i]->getName().c_str() << endl;
	}

	File* getFile(string s)
	{
		for(int i=0;i<files.size();++i)
		{
			if(!files[i]->getName().compare(s)) 
				return files[i];
			else 
				cout<<"file not founded"<<endl;
		}
		return nullptr;
	}

	Folder* getFolder(string s)
	{
		int i = 0;

		Folder* tmpFolder = this;

		while(i < s.length())
		{

			string nextFolder = "";

			while(s.size() != i)
			{
				if(s[i] != '/') 
				{
					nextFolder+=s[i];
					i++;
				}else break;
			}

			for(int j = 0;j < tmpFolder->getFolderSize(); ++j)
			{
				if(!tmpFolder->folders[j]->getName().compare(nextFolder))
				{
					tmpFolder = tmpFolder->folders[j];
					i++;
					break;
				}
			}

		}

		return tmpFolder;
	}

};

class FileSystem
{
	Folder root;

public:
	FileSystem(string s)
	{
		root = Folder(s);
	}

	Folder& getRoot()
	{
		return root;
	}

	Folder* getFolder(string s)
	{
		return root.getFolder(s);
	}

	void show()
	{
		root.show();
	}

	void addFolder(string s)
	{
		bool b = false;

		for(int i = 0; i < s.length(); ++i)
			if(s[i] == '/') b = true;

		if(b)
		{
			string folder;
			string newFolder;

			int i = s.length()-1;
		
			if(root.getFolderSize() > 0)

			while(s[i] != '/') 
				i--;

			i++;

			for(int j=0;j<i-1;++j)
				folder+=s[j];

			for(; i < s.length(); ++i)
				newFolder+=s[i];

			root.getFolder(folder)->addFolder(newFolder);
		} else
			root.addFolder(s);
	}

	void addFile(string s, string text)
	{
		bool b = false;

		for(int i = 0; i < s.length(); ++i)
			if(s[i] == '/') b = true;

		if(b)
		{
			string folder;
			string newFile;

			int i = s.length()-1;
		
			if(root.getFolderSize() > 0)

			while(s[i] != '/') 
				i--;

			i++;

			for(int j=0;j<i-1;++j)
				folder+=s[j];

			for(; i < s.length(); ++i)
				newFile+=s[i];

			root.getFolder(folder)->addFile(newFile, text);
		} else
			root.addFile(s, text);
	}

};


int main()
{
	FileSystem fs("C");
	fs.addFolder("music");
	fs.addFolder("games");
	fs.addFolder("pictures");
	fs.addFolder("music/rock");
	fs.addFolder("music/pop");
	fs.addFile("music/rock/Toxic.mp3", "our last night - toxic");
	fs.show();
	cout<<endl;
	fs.getFolder("music/rock")->getFile("Toxic.mp3")->printText();
	fs.getRoot().del();
	cin.get();
	return 0;
}
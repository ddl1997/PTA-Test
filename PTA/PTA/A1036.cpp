#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	string mName, mId, fName, fId;
	int mMin = 200, fMax = -1;
	bool mAbsent = true, fAbsent = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, id;
		char gender;
		int grade;
		cin >> name >> gender >> id >> grade;
		if (gender == 'M')
		{
			mAbsent = false;
			if (grade < mMin)
			{
				mName = name;
				mId = id;
				mMin = grade;
			}
		}
		else
		{
			fAbsent = false;
			if (grade > fMax)
			{
				fName = name;
				fId = id;
				fMax = grade;
			}
		}
	}

	if (!mAbsent && !fAbsent)
	{
		int diff = fMax - mMin;
		cout << fName << ' ' << fId << endl << mName << ' ' << mId << endl << diff << endl;
	}
	else
	{
		if (fAbsent)
			cout << "Absent" << endl;
		else
			cout << fName << ' ' << fId << endl;
		if (mAbsent)
			cout << "Absent" << endl;
		else
			cout << mName << ' ' << mId << endl;
		cout << "NA" << endl;
	}

	return 0;
}
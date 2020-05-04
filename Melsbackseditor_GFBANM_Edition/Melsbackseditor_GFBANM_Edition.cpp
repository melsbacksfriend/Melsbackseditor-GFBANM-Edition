// Melsbackseditor_GFBANM_Edition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <time.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;

void delay(int num)
{
    int now, later;

    time_t seconds; // time_t struct

    now = time(NULL); //get current time

    later = now + num; //determine how long from now to stop (future time)

    while (time(NULL) < later)

    {/*do nothing*/
    } /*this just hangs out until it reaches future time*/
    return;
}

int main(int argc, char *argv[])
{
    cout << "WARNING!\nThis software was written by someone with\nANGER ISSUES!\nI'm not responsible for any damage!\n(I doubt there will be any tho)\nTo continue, do nothing until 15 sec have passed.\nTo exit, close this window before then.\n";
    delay(15);
    size_t found;
    size_t found2;
    size_t found3;
    size_t found4;
    size_t found5;
    size_t found6;
    size_t found7;
    size_t found8;
    size_t found9;
    size_t found10;
    size_t found11;
    size_t found12;
    size_t found13;
    string filecontent[100000];
    string inpath;
    string inpath2;
    int bonecount;
    int framecount;
    int matcount;
    int texcount;
    int shadercount;
    string outpath;
    string xtransstr[15000];
    string ytransstr[15000];
    string ztransstr[15000];
    string xrotstr[15000];
    string yrotstr[15000];
    string zrotstr[15000];
    float xtransflt[15000];
    float ytransflt[15000];
    float ztransflt[15000];
    float xrotflt[15000];
    float yrotflt[15000];
    float zrotflt[15000];
    int xrotconv[15000];
    int yrotconv[15000];
    int zrotconv[15000];
    string matname[20];
    string val[15000];
    string valtrunc[15000];
    string colvaltrunc[15000];
    string switchval[15000];
    string colval[15000];
    int valbegin[20];
    int valend[20];
    int switchbegin[20];
    int switchend[20];
    int colbegin[20];
    int colend[20];
    int valdif[20];
    int switchdif[20];
    int coldif[20];
    cout << "Please enter path to .smd animation.\n";
    getline(cin, inpath);
    cout << "Please enter name of the output file minus the extension.\n";
    getline(cin, outpath);
    cout << "Please enter path to .json obtained using\nflatc on your .gfbmdl.\n";
    getline(cin, inpath2);
    cout << "How many bones are in the model?\nRemember that in the .smd,\nindices start with 0\n(Up to 150 supported)\n";
    cin >> bonecount;
    cout << "How many materials in the model?\n";
    cin >> matcount;
    cout << "How many shaders?\n";
    cin >> shadercount;
    cout << "How many textures?\n";
    cin >> texcount;
    string bonename[] = {"", "", "", "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
    ifstream infile(inpath);
    streampos size = infile.tellg();
    ofstream outfile("deleteme.json");
    ifstream infile2(inpath2);
    streampos size2 = infile2.tellg();
    for (int i = 0; i < (texcount + shadercount + 18); i++)
    {
        infile2.ignore(256, '\n');
    }
    for (int i = 0; i < matcount; i++)
    {
        infile2.ignore(256, '\"');
        getline(infile2, matname[i], '\"');
    }
    infile.ignore(256, '\n');
    for (int i = 1; i <= bonecount; i++)
    {
        infile.ignore(256, '\n');
        infile.ignore(256, '\"');
        getline(infile, bonename[i - 1], '\"');
    }
    infile2.seekg(0);
    cout << "Put in the starting lines of the\nswitches minus 1 in order.\n";
    for (int i = 0; i < matcount; i++)
    {
        cin >> switchbegin[i];
    }
    cout << "Now time for ending lines of the same thing.\n";
    for (int i = 0; i < matcount; i++)
    {
        cin >> switchend[i];
    }
    cout << "Now for the starts of the values minus 1.\n";
    for (int i = 0; i < matcount; i++)
    {
        cin >> valbegin[i];
    }
    cout << "Now for ends of same thing.\n";
    for (int i = 0; i < matcount; i++)
    {
        cin >> valend[i];
    }
    cout << "Starts of colors that weave into a spire of flame minus 1.\n";
    for (int i = 0; i < matcount; i++)
    {
        cin >> colbegin[i];
    }
    cout << "Ends of same thing.\n";
    for (int i = 0; i < matcount; i++)
    {
        cin >> colend[i];
    }
    for (int i = 0; i < matcount; i++)
    {
        switchdif[i] = switchend[i] - switchbegin[i];
        valdif[i] = valend[i] - valbegin[i];
        coldif[i] = colend[i] - colbegin[i];
    }
    for (int i = 0; i < matcount; i++)
      {
        infile2.seekg(0);
        for (int j = 0; j < switchbegin[i]; j++)
        {
            infile2.ignore(256, '\n');
        }
        for (int j = 0; j < switchdif[i]; j++)
        {
            if (i != 0 && switchdif[i] < switchdif[i - 1]) getline(infile2, switchval[j + (i * switchdif[i - 1])], '\n');
            else if (i != 0 && switchdif[i] > switchdif[i - 1] && switchdif[i] < switchdif[i + 1]) getline(infile2, switchval[j + (i * switchdif[i + 1])], '\n');
            else getline(infile2, switchval[j + (i * switchdif[i])], '\n');

        }
        infile2.seekg(0);
        for (int j = 0; j < valbegin[i]; j++)
        {
            infile2.ignore(256, '\n');
        }
        for (int j = 0; j < valdif[i]; j++)
        {
            if (i != 0 && valdif[i] < valdif[i - 1]) getline(infile2, val[j + (i * valdif[i - 1])], '\n');
            else if (i != 0 && valdif[i] > valdif[i - 1] && valdif[i] < valdif[i + 1]) getline(infile2, val[j + (i * valdif[i + 1])], '\n');
            else getline(infile2, val[j + (i * valdif[i])], '\n');
        }
        infile2.seekg(0);
        for (int j = 0; j < colbegin[i]; j++)
        {
            infile2.ignore(256, '\n');
        }
        for (int j = 0; j < coldif[i]; j++)
        {
            getline(infile2, colval[j + (i * coldif[i])], '\n');
        }
    }
    for (int i = 0; i < matcount; i++)
    {
        for (int j = 0; j < coldif[i]; j++)
        {
            found7 = colval[j + (i * coldif[i])].find('R');
            if (found7 != string::npos)
            {
                colval[j + (i * coldif[i])].replace(found7, 1, 'R', 'X');
                colval[j + (i * coldif[i])].erase(found7, 81);
            }
            found8 = colval[j + (i * coldif[i])].find('G');
            if (found8 != string::npos)
            {
                colval[j + (i * coldif[i])].replace(found8, 1, 'G', 'Y');
                colval[j + (i * coldif[i])].erase(found8, 70);
            }
            found9 = colval[j + (i * coldif[i])].find('B');
            if (found9 != string::npos)
            {
                colval[j + (i * coldif[i])].replace(found9, 1, 'B', 'Z');
                colval[j + (i * coldif[i])].erase(found9, 65);
            }
        }
    }
    for (int i = 0; i < matcount; i++)
    {
        for (int j = 0; j < valdif[i]; j++)
        {
            valtrunc[j + (i * valdif[i])] = val[j + (i * valdif[i])];
            found10 = valtrunc[j + (i * valdif[i])].find("          Value:");
            if (found10 != string::npos)
            {
                valtrunc[j + (i * valdif[i])].erase(valtrunc[j + (i * valdif[i])].begin() + 17, valtrunc[j + (i * valdif[i])].end());
            }
        }
        for (int j = 0; j < coldif[i]; j++)
        {
            colvaltrunc[j + (i * coldif[i])] = colval[j + (i * coldif[i])];
            found11 = colvaltrunc[j + (i * coldif[i])].find("            X:");
            if (found11 != string::npos)
            {
                colvaltrunc[j + (i * coldif[i])].erase(colvaltrunc[j + (i * coldif[i])].begin() + 15, colvaltrunc[j + (i * coldif[i])].end());
            }
            found12 = colvaltrunc[j + (i * coldif[i])].find("            Y:");
            if (found12 != string::npos)
            {
                colvaltrunc[j + (i * coldif[i])].erase(colvaltrunc[j + (i * coldif[i])].begin() + 15, colvaltrunc[j + (i * coldif[i])].end());
            }
            found13 = colvaltrunc[j + (i * coldif[i])].find("            Z:");
            if (found13 != string::npos)
            {
                colvaltrunc[j + (i * coldif[i])].erase(colvaltrunc[j + (i * coldif[i])].begin() + 15, colvaltrunc[j + (i * coldif[i])].end());
            }
        }
    }
    cout << "How many frames?\nRemember that in the .smd,\nindices start with 0\n(Up to 100 supported)\n";
    cin >> framecount;
    infile.ignore(256, '\n');
    infile.ignore(256, '\n');
    for (int i = 0; i < framecount; i++)
    {
        infile.ignore(256, '\n');
        for (int j = 0; j < bonecount; j++)
        {
            infile.ignore(256, ' ');
            getline(infile, xtransstr[j + (i * bonecount)], ' ');
            getline(infile, ytransstr[j + (i * bonecount)], ' ');
            getline(infile, ztransstr[j + (i * bonecount)], ' ');
            getline(infile, xrotstr[j + (i * bonecount)], ' ');
            getline(infile, yrotstr[j + (i * bonecount)], ' ');
            getline(infile, zrotstr[j + (i * bonecount)], '\n');
        }
    }
    for (int i = 0; i < (bonecount * framecount); i++)
    {
        found = xtransstr[i].find('E');
        if (found != string::npos)
        {
            xtransstr[i].replace(found, 1, 'E', 'e');
            xtransstr[i].erase(found, 68);
        }
        found2 = ytransstr[i].find('E');
        if (found2 != string::npos)
        {
            ytransstr[i].replace(found2, 1, 'E', 'e');
            ytransstr[i].erase(found2, 68);
        }
        found3 = ztransstr[i].find('E');
        if (found3 != string::npos)
        {
            ztransstr[i].replace(found3, 1, 'E', 'e');
            ztransstr[i].erase(found3, 68);
        }
        found4 = xrotstr[i].find('E');
        if (found4 != string::npos)
        {
            xrotstr[i].replace(found4, 1, 'E', 'e');
            xrotstr[i].erase(found4, 68);
        }
        found5 = yrotstr[i].find('E');
        if (found5 != string::npos)
        {
            yrotstr[i].replace(found5, 1, 'E', 'e');
            yrotstr[i].erase(found5, 68);
        }
        found6 = zrotstr[i].find('E');
        if (found6 != string::npos)
        {
            zrotstr[i].replace(found6, 1, 'E', 'e');
            zrotstr[i].erase(found6, 68);
        }
    }
    for (int i = 0; i < (bonecount * framecount); i++)
    {
        if (xtransstr[i] != "NaN")
        {
            xtransflt[i] = stof(xtransstr[i]);
        }
        else
        {
            xtransflt[i] = 0;
        }
        if (ytransstr[i] != "NaN")
        {
            ytransflt[i] = stof(ytransstr[i]);
        }
        else
        {
            ytransflt[i] = 0;
        }
        if (ztransstr[i] != "NaN")
        {
            ztransflt[i] = stof(ztransstr[i]);
        }
        else
        {
            ztransflt[i] = 0;
        }
        if (xrotstr[i] != "NaN")
        {
            xrotflt[i] = stof(xrotstr[i]);
        }
        else
        {
            xrotflt[i] = 0;
        }
        if (yrotstr[i] != "NaN")
        {
            yrotflt[i] = stof(yrotstr[i]);
        }
        else
        {
            yrotflt[i] = 0;
        }
        if (zrotstr[i] != "NaN")
        {
            zrotflt[i] = stof(zrotstr[i]);
        }
        else
        {
            zrotflt[i] = 0;
        }
    }
    for (int i = 0; i < (bonecount * framecount); i++)
    {
        if (xrotflt[i] < 0)
        {
            xrotconv[i] = xrotflt[i] * 10430.21919553;
            xrotconv[i] = xrotconv[i] + 65535;
        }
        else
        {
            xrotconv[i] = xrotflt[i] * 10430.21919553;
        }
        if (yrotflt[i] < 0)
        {
            yrotconv[i] = yrotflt[i] * 10430.21919553;
            yrotconv[i] = yrotconv[i] + 65535;
        }
        else
        {
            yrotconv[i] = yrotflt[i] * 10430.21919553;
        }
        if (zrotflt[i] < 0)
        {
            zrotconv[i] = zrotflt[i] * 10430.21919553;
            zrotconv[i] = zrotconv[i] + 65535;
        }
        else
        {
            zrotconv[i] = zrotflt[i] * 10430.21919553;
        }
    }
    char looptrue;
    cout << "Does your anim loop?\ny for yes, n for no\n";
    cin >> looptrue;
    if (looptrue == 'y') outfile << "{\n  AnimConfig: {\n    Unknown: 1,\n    KeyFrames: " << framecount << ",\n    FramesPerSecond: 30\n  },\n  Bones: {\n    Bones: [\n";
    if (looptrue == 'n') outfile << "{\n  AnimConfig: {\n    KeyFrames: " << framecount << ",\n    FramesPerSecond: 30\n  },\n  Bones: {\n    Bones: [\n";
    for (int i = 0; i < bonecount; i++)
    {
        outfile << "      {\n        Name: \"" << bonename[i] << "\",\n        Scale_type: \"FixedVectorTrack\",\n        Scale: {\n          Value: {\n            X: 1.0,\n            Y: 1.0,\n            Z: 1.0\n          }\n        },\n        Rotate_type: \"DynamicRotationTrack\",\n        Rotate: {\n          Values: [\n";
        for (int j = 0; j < framecount; j++)
        {
            if (j < (framecount - 1)) outfile << "            {\n              X: " << xrotconv[i + (j * bonecount)] << ",\n              Y: " << yrotconv[i + (j * bonecount)] << ",\n              Z: " << zrotconv[i + (j * bonecount)] << "\n            },\n";
            if (j == (framecount - 1)) outfile << "            {\n              X: " << xrotconv[i + (j * bonecount)] << ",\n              Y: " << yrotconv[i + (j * bonecount)] << ",\n              Z: " << zrotconv[i + (j * bonecount)] << "\n            }\n";
        }
        outfile << "          ]\n        },\n        Translate_type: \"DynamicVectorTrack\",\n        Translate: {\n          Values: [\n";
        for (int j = 0; j < framecount; j++)
        {
            if (j < (framecount - 1)) outfile << "            {\n              X: " << fixed << xtransflt[i + (j * bonecount)] << ",\n              Y: " << ytransflt[i + (j * bonecount)] << ",\n              Z: " << ztransflt[i + (j * bonecount)] << "\n            },\n";
            if (j == (framecount - 1)) outfile << "            {\n              X: " << fixed << xtransflt[i + (j * bonecount)] << ",\n              Y: " << ytransflt[i + (j * bonecount)] << ",\n              Z: " << ztransflt[i + (j * bonecount)] << "\n            }\n";
        }
        if (i < (bonecount - 1)) outfile << "          ]\n        }\n      },\n";
        if (i == (bonecount - 1)) outfile << "          ]\n        }\n      }\n    ]\n  },\n";
    }
    outfile << "  Materials: {\n    Materials: [\n";
    for (int i = 0; i < matcount; i++)
    {
        outfile << "      {\n        Name: \"" << matname[i] << "\",\n        Switches: [\n";
        for (int j = 0; j < switchdif[i]; j++)
        {
            if (i != 0 && switchdif[i] < switchdif[i - 1])
            {
                if (switchval[j + (i * switchdif[i - 1])] == "        {") outfile << "          {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"useColorTex\"," || switchval[j + (i * switchdif[i - 1])] == "          Name: \"useColorTex\"") outfile << "            Name: \"useColorTex\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Value: true") outfile << "              Value: 1\n";
                if (switchval[j + (i * switchdif[i - 1])] == "        },") outfile << "            }\n          },\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"SwitchEmissionMaskTexUV\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"SwitchEmissionMaskTexUV\",") outfile << "            Name: \"SwitchEmissionMaskTexUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"EmissionMaskUse\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"EmissionMaskUse\",") outfile << "            Name: \"EmissionMaskUse\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"SwitchPriority\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"SwitchPriority\",") outfile << "            Name: \"SwitchPriority\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"Layer1Enable\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"Layer1Enable\",") outfile << "            Name: \"Layer1Enable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"SwitchAmbientTexUV\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"SwitchAmbientTexUV\",") outfile << "            Name: \"SwitchAmbientTexUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"AmbientMapEnable\"," || switchval[j + (i * switchdif[i - 1])] == "          Name: \"AmbientMapEnable\"") outfile << "            Name: \"AmbientMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"SwitchNormalMapUV\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"SwitchNormalMapUV\",") outfile << "            Name: \"SwitchNormalMapUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"NormalMapEnable\"," || switchval[j + (i * switchdif[i - 1])] == "          Name: \"NormalMapEnable\"") outfile << "            Name: \"NormalMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"LightTableEnable\"," || switchval[j + (i * switchdif[i - 1])] == "          Name: \"LightTableEnable\"") outfile << "            Name: \"LightTableEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"SpecularMaskEnable\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"SpecularMaskEnable\",") outfile << "            Name: \"SpecularMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"BaseColorAddEnable\"," || switchval[j + (i * switchdif[i - 1])] == "          Name: \"BaseColorAddEnable\"") outfile << "            Name: \"BaseColorAddEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"SphereMapEnable\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"SphereMapEnable\",") outfile << "            Name: \"SphereMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"SphereMaskEnable\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"SphereMaskEnable\",") outfile << "            Name: \"SphereMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"RimMaskEnable\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"RimMaskEnable\",") outfile << "            Name: \"RimMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"alphaShell\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"alphaShell\",") outfile << "            Name: \"alphaShell\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"EffectVal\"," || switchval[j + (i * switchdif[i - 1])] == "          Name: \"EffectVal\"") outfile << "            Name: \"EffectVal\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"NormalEdgeEnable\"," || switchval[j + (i * switchdif[i - 1])] == "          Name: \"NormalEdgeEnable\"") outfile << "            Name: \"NormalEdgeEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"OutLineIDEnable\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"OutLineIDEnable\",") outfile << "            Name: \"OutLineIDEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "          Name: \"OutLineColFixed\"" || switchval[j + (i * switchdif[i - 1])] == "          Name: \"OutLineColFixed\",") outfile << "            Name: \"OutLineColFixed\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i - 1])] == "        }") outfile << "            }\n          }\n        ],\n";
            }
            else if (i != 0 && switchdif[i] > switchdif[i - 1] && switchdif[i] < switchdif[i + 1])
            {
                if (switchval[j + (i * switchdif[i + 1])] == "        {") outfile << "          {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"useColorTex\"," || switchval[j + (i * switchdif[i + 1])] == "          Name: \"useColorTex\"") outfile << "            Name: \"useColorTex\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Value: true") outfile << "              Value: 1\n";
                if (switchval[j + (i * switchdif[i + 1])] == "        },") outfile << "            }\n          },\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"SwitchEmissionMaskTexUV\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"SwitchEmissionMaskTexUV\",") outfile << "            Name: \"SwitchEmissionMaskTexUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"EmissionMaskUse\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"EmissionMaskUse\",") outfile << "            Name: \"EmissionMaskUse\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"SwitchPriority\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"SwitchPriority\",") outfile << "            Name: \"SwitchPriority\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"Layer1Enable\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"Layer1Enable\",") outfile << "            Name: \"Layer1Enable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"SwitchAmbientTexUV\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"SwitchAmbientTexUV\",") outfile << "            Name: \"SwitchAmbientTexUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"AmbientMapEnable\"," || switchval[j + (i * switchdif[i + 1])] == "          Name: \"AmbientMapEnable\"") outfile << "            Name: \"AmbientMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"SwitchNormalMapUV\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"SwitchNormalMapUV\",") outfile << "            Name: \"SwitchNormalMapUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"NormalMapEnable\"," || switchval[j + (i * switchdif[i + 1])] == "          Name: \"NormalMapEnable\"") outfile << "            Name: \"NormalMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"LightTableEnable\"," || switchval[j + (i * switchdif[i + 1])] == "          Name: \"LightTableEnable\"") outfile << "            Name: \"LightTableEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"SpecularMaskEnable\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"SpecularMaskEnable\",") outfile << "            Name: \"SpecularMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"BaseColorAddEnable\"," || switchval[j + (i * switchdif[i + 1])] == "          Name: \"BaseColorAddEnable\"") outfile << "            Name: \"BaseColorAddEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"SphereMapEnable\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"SphereMapEnable\",") outfile << "            Name: \"SphereMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"SphereMaskEnable\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"SphereMaskEnable\",") outfile << "            Name: \"SphereMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"RimMaskEnable\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"RimMaskEnable\",") outfile << "            Name: \"RimMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"alphaShell\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"alphaShell\",") outfile << "            Name: \"alphaShell\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"EffectVal\"," || switchval[j + (i * switchdif[i + 1])] == "          Name: \"EffectVal\"") outfile << "            Name: \"EffectVal\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"NormalEdgeEnable\"," || switchval[j + (i * switchdif[i + 1])] == "          Name: \"NormalEdgeEnable\"") outfile << "            Name: \"NormalEdgeEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"OutLineIDEnable\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"OutLineIDEnable\",") outfile << "            Name: \"OutLineIDEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "          Name: \"OutLineColFixed\"" || switchval[j + (i * switchdif[i + 1])] == "          Name: \"OutLineColFixed\",") outfile << "            Name: \"OutLineColFixed\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i + 1])] == "        }") outfile << "            }\n          }\n        ],\n";
            }
            else
            {
                if (switchval[j + (i * switchdif[i])] == "        {") outfile << "          {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"useColorTex\"," || switchval[j + (i * switchdif[i])] == "          Name: \"useColorTex\"") outfile << "            Name: \"useColorTex\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Value: true") outfile << "              Value: 1\n";
                if (switchval[j + (i * switchdif[i])] == "        },") outfile << "            }\n          },\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"SwitchEmissionMaskTexUV\"" || switchval[j + (i * switchdif[i])] == "          Name: \"SwitchEmissionMaskTexUV\",") outfile << "            Name: \"SwitchEmissionMaskTexUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"EmissionMaskUse\"" || switchval[j + (i * switchdif[i])] == "          Name: \"EmissionMaskUse\",") outfile << "            Name: \"EmissionMaskUse\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"SwitchPriority\"" || switchval[j + (i * switchdif[i])] == "          Name: \"SwitchPriority\",") outfile << "            Name: \"SwitchPriority\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"Layer1Enable\"" || switchval[j + (i * switchdif[i])] == "          Name: \"Layer1Enable\",") outfile << "            Name: \"Layer1Enable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"SwitchAmbientTexUV\"" || switchval[j + (i * switchdif[i])] == "          Name: \"SwitchAmbientTexUV\",") outfile << "            Name: \"SwitchAmbientTexUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"AmbientMapEnable\"," || switchval[j + (i * switchdif[i])] == "          Name: \"AmbientMapEnable\"") outfile << "            Name: \"AmbientMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"SwitchNormalMapUV\"" || switchval[j + (i * switchdif[i])] == "          Name: \"SwitchNormalMapUV\",") outfile << "            Name: \"SwitchNormalMapUV\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"NormalMapEnable\"," || switchval[j + (i * switchdif[i])] == "          Name: \"NormalMapEnable\"") outfile << "            Name: \"NormalMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"LightTableEnable\"," || switchval[j + (i * switchdif[i])] == "          Name: \"LightTableEnable\"") outfile << "            Name: \"LightTableEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"SpecularMaskEnable\"" || switchval[j + (i * switchdif[i])] == "          Name: \"SpecularMaskEnable\",") outfile << "            Name: \"SpecularMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"BaseColorAddEnable\"," || switchval[j + (i * switchdif[i])] == "          Name: \"BaseColorAddEnable\"") outfile << "            Name: \"BaseColorAddEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"SphereMapEnable\"" || switchval[j + (i * switchdif[i])] == "          Name: \"SphereMapEnable\",") outfile << "            Name: \"SphereMapEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"SphereMaskEnable\"" || switchval[j + (i * switchdif[i])] == "          Name: \"SphereMaskEnable\",") outfile << "            Name: \"SphereMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"RimMaskEnable\"" || switchval[j + (i * switchdif[i])] == "          Name: \"RimMaskEnable\",") outfile << "            Name: \"RimMaskEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"alphaShell\"" || switchval[j + (i * switchdif[i])] == "          Name: \"alphaShell\",") outfile << "            Name: \"alphaShell\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"EffectVal\"," || switchval[j + (i * switchdif[i])] == "          Name: \"EffectVal\"") outfile << "            Name: \"EffectVal\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"NormalEdgeEnable\"," || switchval[j + (i * switchdif[i])] == "          Name: \"NormalEdgeEnable\"") outfile << "            Name: \"NormalEdgeEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"OutLineIDEnable\"" || switchval[j + (i * switchdif[i])] == "          Name: \"OutLineIDEnable\",") outfile << "            Name: \"OutLineIDEnable\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "          Name: \"OutLineColFixed\"" || switchval[j + (i * switchdif[i])] == "          Name: \"OutLineColFixed\",") outfile << "            Name: \"OutLineColFixed\",\n            Value_type: \"FixedBooleanTrack\",\n            Value: {\n";
                if (switchval[j + (i * switchdif[i])] == "        }") outfile << "            }\n          }\n        ],\n";
            }
        }
        outfile << "        Values: [\n";
        for (int j = 0; j < valdif[i]; j++)
        {
            if (i != 0 && valdif[i] < valdif[i - 1])
            {
                if (valtrunc[j + (i * valdif[i - 1])] == "          Value: ") outfile << "    " << val[j + (i * valdif[i - 1])] << endl;
                if (val[j + (i * valdif[i - 1])] == "        {") outfile << "          {\n";
                if (val[j + (i * valdif[i - 1])] == "        },") outfile << "            }\n          },\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ColorUVScaleU\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ColorUVScaleU\"") outfile << "            Name: \"ColorUVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ColorUVScaleV\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ColorUVScaleV\"") outfile << "            Name: \"ColorUVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ColorUVTranslateU\"" || val[j + (i * valdif[i - 1])] == "          Name: \"ColorUVTranslateU\",") outfile << "            Name: \"ColorUVTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ColorBaseU\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ColorBaseU\"") outfile << "            Name: \"ColorBaseU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ColorUVTranslateV\"" || val[j + (i * valdif[i - 1])] == "          Name: \"ColorUVTranslateV\",") outfile << "            Name: \"ColorUVTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ColorBaseV\"" || val[j + (i * valdif[i - 1])] == "          Name: \"ColorBaseV\",") outfile << "            Name: \"ColorBaseV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColor0Val\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColor0Val\"") outfile << "            Name: \"ConstantColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Layer1UVScaleU\"," || val[j + (i * valdif[i - 1])] == "          Name: \"Layer1UVScaleU\"") outfile << "            Name: \"Layer1UVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Layer1UVScaleV\"," || val[j + (i * valdif[i - 1])] == "          Name: \"Layer1UVScaleV\"") outfile << "            Name: \"Layer1UVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Layer1UVTranslateU\"" || val[j + (i * valdif[i - 1])] == "          Name: \"Layer1UVTranslateU\",") outfile << "            Name: \"Layer1UVTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Layer1BaseU\"" || val[j + (i * valdif[i - 1])] == "          Name: \"Layer1BaseU\",") outfile << "            Name: \"Layer1BaseU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Layer1UVTranslateV\"" || val[j + (i * valdif[i - 1])] == "          Name: \"Layer1UVTranslateV\",") outfile << "            Name: \"Layer1UVTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Layer1BaseV\"" || val[j + (i * valdif[i - 1])] == "          Name: \"Layer1BaseV\",") outfile << "            Name: \"Layer1BaseV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"EmissionMaskVal\"," || val[j + (i * valdif[i - 1])] == "          Name: \"EmissionMaskVal\"") outfile << "            Name: \"EmissionMaskVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColorSd0Val\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColorSd0Val\"") outfile << "            Name: \"ConstantColorSd0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColor1Val\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColor1Val\"") outfile << "            Name: \"ConstantColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColorSd1Val\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColorSd1Val\"") outfile << "            Name: \"ConstantColorSd1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ColorLerpValue\"" || val[j + (i * valdif[i - 1])] == "          Name: \"ColorLerpValue\",") outfile << "            Name: \"ColorLerpValue\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"L1ConstantColor0Val\"," || val[j + (i * valdif[i - 1])] == "          Name: \"L1ConstantColor0Val\"") outfile << "            Name: \"L1ConstantColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"L1AddColor0Val\"" || val[j + (i * valdif[i - 1])] == "          Name: \"L1AddColor0Val\",") outfile << "            Name: \"L1AddColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"L1ConstantColor1Val\"," || val[j + (i * valdif[i - 1])] == "          Name: \"L1ConstantColor1Val\"") outfile << "            Name: \"L1ConstantColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"L1AddColor1Val\"" || val[j + (i * valdif[i - 1])] == "          Name: \"L1AddColor1Val\",") outfile << "            Name: \"L1AddColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"L1ConstantColorSd0Val\"," || val[j + (i * valdif[i - 1])] == "          Name: \"L1ConstantColorSd0Val\"") outfile << "            Name: \"L1ConstantColorSd0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"L1ConstantColorSd1Val\"," || val[j + (i * valdif[i - 1])] == "          Name: \"L1ConstantColorSd1Val\"") outfile << "            Name: \"L1ConstantColorSd1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Layer1OverLerpValue\"," || val[j + (i * valdif[i - 1])] == "          Name: \"Layer1OverLerpValue\"") outfile << "            Name: \"Layer1OverLerpValue\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"NormalMapUVScaleU\"," || val[j + (i * valdif[i - 1])] == "          Name: \"NormalMapUVScaleU\"") outfile << "            Name: \"NormalMapUVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"NormalMapUVScaleV\"," || val[j + (i * valdif[i - 1])] == "          Name: \"NormalMapUVScaleV\"") outfile << "            Name: \"NormalMapUVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"LightTblIndex\"," || val[j + (i * valdif[i - 1])] == "          Name: \"LightTblIndex\"") outfile << "            Name: \"LightTblIndex\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"LightMul\"," || val[j + (i * valdif[i - 1])] == "          Name: \"LightMul\"") outfile << "            Name: \"LightMul\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"SpecularPower\"," || val[j + (i * valdif[i - 1])] == "          Name: \"SpecularPower\"") outfile << "            Name: \"SpecularPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"SpecularScale\"," || val[j + (i * valdif[i - 1])] == "          Name: \"SpecularScale\"") outfile << "            Name: \"SpecularScale\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"SphereMapColorVal\"," || val[j + (i * valdif[i - 1])] == "          Name: \"SphereMapColorVal\"") outfile << "            Name: \"SphereMapColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"RimColorVal\"," || val[j + (i * valdif[i - 1])] == "          Name: \"RimColorVal\"") outfile << "            Name: \"RimColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"RimPower\"," || val[j + (i * valdif[i - 1])] == "          Name: \"RimPower\"") outfile << "            Name: \"RimPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"RimStrength\"," || val[j + (i * valdif[i - 1])] == "          Name: \"RimStrength\"") outfile << "            Name: \"RimStrength\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Def0_OneMin1_FreCol\"," || val[j + (i * valdif[i - 1])] == "          Name: \"Def0_OneMin1_FreCol\"") outfile << "            Name: \"Def0_OneMin1_FreCol\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"DistortionIntensity\"," || val[j + (i * valdif[i - 1])] == "          Name: \"DistortionIntensity\"") outfile << "            Name: \"DistortionIntensity\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"Sin01\"," || val[j + (i * valdif[i - 1])] == "          Name: \"Sin01\"") outfile << "            Name: \"Sin01\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ScaleUV\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ScaleUV\"") outfile << "            Name: \"ScaleUV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexTranslateU\"" || val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexTranslateU\",") outfile << "            Name: \"EffectTexTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexTranslateV\"" || val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexTranslateV\",") outfile << "            Name: \"EffectTexTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexRotate\"" || val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexRotate\",") outfile << "            Name: \"EffectTexRotate\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexScaleU\"," || val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexScaleU\"") outfile << "            Name: \"EffectTexScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexScaleV\"," || val[j + (i * valdif[i - 1])] == "          Name: \"EffectTexScaleV\"") outfile << "            Name: \"EffectTexScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"EffectColPower\"," || val[j + (i * valdif[i - 1])] == "          Name: \"EffectColPower\"") outfile << "            Name: \"EffectColPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"OnGameEmissionVal\"," || val[j + (i * valdif[i - 1])] == "          Name: \"OnGameEmissionVal\"") outfile << "            Name: \"OnGameEmissionVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColorVal\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ConstantColorVal\"") outfile << "            Name: \"ConstantColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ConstantAlpha\"," || val[j + (i * valdif[i - 1])] == "          Name: \"ConstantAlpha\"") outfile << "            Name: \"ConstantAlpha\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"OnGameColorVal\"," || val[j + (i * valdif[i - 1])] == "          Name: \"OnGameColorVal\"") outfile << "            Name: \"OnGameColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"OnGameAlpha\"," || val[j + (i * valdif[i - 1])] == "          Name: \"OnGameAlpha\"") outfile << "            Name: \"OnGameAlpha\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"OutLineID\"" || val[j + (i * valdif[i - 1])] == "          Name: \"OutLineID\",") outfile << "            Name: \"OutLineID\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "          Name: \"ProgID\"" || val[j + (i * valdif[i - 1])] == "          Name: \"ProgID\",") outfile << "            Name: \"ProgID\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i - 1])] == "        }") outfile << "            }\n          }\n        ],\n";
            }
            else if (i != 0 && valdif[i] > valdif[i - 1] && valdif[i] < valdif[i + 1])
            {
                if (valtrunc[j + (i * valdif[i + 1])] == "          Value: ") outfile << "    " << val[j + (i * valdif[i + 1])] << endl;
                if (val[j + (i * valdif[i + 1])] == "        {") outfile << "          {\n";
                if (val[j + (i * valdif[i + 1])] == "        },") outfile << "            }\n          },\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ColorUVScaleU\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ColorUVScaleU\"") outfile << "            Name: \"ColorUVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ColorUVScaleV\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ColorUVScaleV\"") outfile << "            Name: \"ColorUVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ColorUVTranslateU\"" || val[j + (i * valdif[i + 1])] == "          Name: \"ColorUVTranslateU\",") outfile << "            Name: \"ColorUVTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ColorBaseU\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ColorBaseU\"") outfile << "            Name: \"ColorBaseU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ColorUVTranslateV\"" || val[j + (i * valdif[i + 1])] == "          Name: \"ColorUVTranslateV\",") outfile << "            Name: \"ColorUVTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ColorBaseV\"" || val[j + (i * valdif[i + 1])] == "          Name: \"ColorBaseV\",") outfile << "            Name: \"ColorBaseV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColor0Val\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColor0Val\"") outfile << "            Name: \"ConstantColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Layer1UVScaleU\"," || val[j + (i * valdif[i + 1])] == "          Name: \"Layer1UVScaleU\"") outfile << "            Name: \"Layer1UVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Layer1UVScaleV\"," || val[j + (i * valdif[i + 1])] == "          Name: \"Layer1UVScaleV\"") outfile << "            Name: \"Layer1UVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Layer1UVTranslateU\"" || val[j + (i * valdif[i + 1])] == "          Name: \"Layer1UVTranslateU\",") outfile << "            Name: \"Layer1UVTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Layer1BaseU\"" || val[j + (i * valdif[i + 1])] == "          Name: \"Layer1BaseU\",") outfile << "            Name: \"Layer1BaseU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Layer1UVTranslateV\"" || val[j + (i * valdif[i + 1])] == "          Name: \"Layer1UVTranslateV\",") outfile << "            Name: \"Layer1UVTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Layer1BaseV\"" || val[j + (i * valdif[i + 1])] == "          Name: \"Layer1BaseV\",") outfile << "            Name: \"Layer1BaseV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"EmissionMaskVal\"," || val[j + (i * valdif[i + 1])] == "          Name: \"EmissionMaskVal\"") outfile << "            Name: \"EmissionMaskVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColorSd0Val\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColorSd0Val\"") outfile << "            Name: \"ConstantColorSd0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColor1Val\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColor1Val\"") outfile << "            Name: \"ConstantColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColorSd1Val\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColorSd1Val\"") outfile << "            Name: \"ConstantColorSd1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ColorLerpValue\"" || val[j + (i * valdif[i + 1])] == "          Name: \"ColorLerpValue\",") outfile << "            Name: \"ColorLerpValue\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"L1ConstantColor0Val\"," || val[j + (i * valdif[i + 1])] == "          Name: \"L1ConstantColor0Val\"") outfile << "            Name: \"L1ConstantColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"L1AddColor0Val\"" || val[j + (i * valdif[i + 1])] == "          Name: \"L1AddColor0Val\",") outfile << "            Name: \"L1AddColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"L1ConstantColor1Val\"," || val[j + (i * valdif[i + 1])] == "          Name: \"L1ConstantColor1Val\"") outfile << "            Name: \"L1ConstantColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"L1AddColor1Val\"" || val[j + (i * valdif[i + 1])] == "          Name: \"L1AddColor1Val\",") outfile << "            Name: \"L1AddColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"L1ConstantColorSd0Val\"," || val[j + (i * valdif[i + 1])] == "          Name: \"L1ConstantColorSd0Val\"") outfile << "            Name: \"L1ConstantColorSd0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"L1ConstantColorSd1Val\"," || val[j + (i * valdif[i + 1])] == "          Name: \"L1ConstantColorSd1Val\"") outfile << "            Name: \"L1ConstantColorSd1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Layer1OverLerpValue\"," || val[j + (i * valdif[i + 1])] == "          Name: \"Layer1OverLerpValue\"") outfile << "            Name: \"Layer1OverLerpValue\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"NormalMapUVScaleU\"," || val[j + (i * valdif[i + 1])] == "          Name: \"NormalMapUVScaleU\"") outfile << "            Name: \"NormalMapUVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"NormalMapUVScaleV\"," || val[j + (i * valdif[i + 1])] == "          Name: \"NormalMapUVScaleV\"") outfile << "            Name: \"NormalMapUVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"LightTblIndex\"," || val[j + (i * valdif[i + 1])] == "          Name: \"LightTblIndex\"") outfile << "            Name: \"LightTblIndex\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"LightMul\"," || val[j + (i * valdif[i + 1])] == "          Name: \"LightMul\"") outfile << "            Name: \"LightMul\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"SpecularPower\"," || val[j + (i * valdif[i + 1])] == "          Name: \"SpecularPower\"") outfile << "            Name: \"SpecularPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"SpecularScale\"," || val[j + (i * valdif[i + 1])] == "          Name: \"SpecularScale\"") outfile << "            Name: \"SpecularScale\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"SphereMapColorVal\"," || val[j + (i * valdif[i + 1])] == "          Name: \"SphereMapColorVal\"") outfile << "            Name: \"SphereMapColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"RimColorVal\"," || val[j + (i * valdif[i + 1])] == "          Name: \"RimColorVal\"") outfile << "            Name: \"RimColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"RimPower\"," || val[j + (i * valdif[i + 1])] == "          Name: \"RimPower\"") outfile << "            Name: \"RimPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"RimStrength\"," || val[j + (i * valdif[i + 1])] == "          Name: \"RimStrength\"") outfile << "            Name: \"RimStrength\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Def0_OneMin1_FreCol\"," || val[j + (i * valdif[i + 1])] == "          Name: \"Def0_OneMin1_FreCol\"") outfile << "            Name: \"Def0_OneMin1_FreCol\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"DistortionIntensity\"," || val[j + (i * valdif[i + 1])] == "          Name: \"DistortionIntensity\"") outfile << "            Name: \"DistortionIntensity\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"Sin01\"," || val[j + (i * valdif[i + 1])] == "          Name: \"Sin01\"") outfile << "            Name: \"Sin01\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ScaleUV\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ScaleUV\"") outfile << "            Name: \"ScaleUV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexTranslateU\"" || val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexTranslateU\",") outfile << "            Name: \"EffectTexTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexTranslateV\"" || val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexTranslateV\",") outfile << "            Name: \"EffectTexTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexRotate\"" || val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexRotate\",") outfile << "            Name: \"EffectTexRotate\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexScaleU\"," || val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexScaleU\"") outfile << "            Name: \"EffectTexScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexScaleV\"," || val[j + (i * valdif[i + 1])] == "          Name: \"EffectTexScaleV\"") outfile << "            Name: \"EffectTexScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"EffectColPower\"," || val[j + (i * valdif[i + 1])] == "          Name: \"EffectColPower\"") outfile << "            Name: \"EffectColPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"OnGameEmissionVal\"," || val[j + (i * valdif[i + 1])] == "          Name: \"OnGameEmissionVal\"") outfile << "            Name: \"OnGameEmissionVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColorVal\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ConstantColorVal\"") outfile << "            Name: \"ConstantColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ConstantAlpha\"," || val[j + (i * valdif[i + 1])] == "          Name: \"ConstantAlpha\"") outfile << "            Name: \"ConstantAlpha\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"OnGameColorVal\"," || val[j + (i * valdif[i + 1])] == "          Name: \"OnGameColorVal\"") outfile << "            Name: \"OnGameColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"OnGameAlpha\"," || val[j + (i * valdif[i + 1])] == "          Name: \"OnGameAlpha\"") outfile << "            Name: \"OnGameAlpha\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"OutLineID\"" || val[j + (i * valdif[i + 1])] == "          Name: \"OutLineID\",") outfile << "            Name: \"OutLineID\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "          Name: \"ProgID\"" || val[j + (i * valdif[i + 1])] == "          Name: \"ProgID\",") outfile << "            Name: \"ProgID\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i + 1])] == "        }") outfile << "            }\n          }\n        ],\n";
            }
            else
            {
                if (valtrunc[j + (i * valdif[i])] == "          Value: ") outfile << "    " << val[j + (i * valdif[i])] << endl;
                if (val[j + (i * valdif[i])] == "        {") outfile << "          {\n";
                if (val[j + (i * valdif[i])] == "        },") outfile << "            }\n          },\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ColorUVScaleU\"," || val[j + (i * valdif[i])] == "          Name: \"ColorUVScaleU\"") outfile << "            Name: \"ColorUVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ColorUVScaleV\"," || val[j + (i * valdif[i])] == "          Name: \"ColorUVScaleV\"") outfile << "            Name: \"ColorUVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ColorUVTranslateU\"" || val[j + (i * valdif[i])] == "          Name: \"ColorUVTranslateU\",") outfile << "            Name: \"ColorUVTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ColorBaseU\"," || val[j + (i * valdif[i])] == "          Name: \"ColorBaseU\"") outfile << "            Name: \"ColorBaseU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ColorUVTranslateV\"" || val[j + (i * valdif[i])] == "          Name: \"ColorUVTranslateV\",") outfile << "            Name: \"ColorUVTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ColorBaseV\"" || val[j + (i * valdif[i])] == "          Name: \"ColorBaseV\",") outfile << "            Name: \"ColorBaseV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ConstantColor0Val\"," || val[j + (i * valdif[i])] == "          Name: \"ConstantColor0Val\"") outfile << "            Name: \"ConstantColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Layer1UVScaleU\"," || val[j + (i * valdif[i])] == "          Name: \"Layer1UVScaleU\"") outfile << "            Name: \"Layer1UVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Layer1UVScaleV\"," || val[j + (i * valdif[i])] == "          Name: \"Layer1UVScaleV\"") outfile << "            Name: \"Layer1UVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Layer1UVTranslateU\"" || val[j + (i * valdif[i])] == "          Name: \"Layer1UVTranslateU\",") outfile << "            Name: \"Layer1UVTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Layer1BaseU\"" || val[j + (i * valdif[i])] == "          Name: \"Layer1BaseU\",") outfile << "            Name: \"Layer1BaseU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Layer1UVTranslateV\"" || val[j + (i * valdif[i])] == "          Name: \"Layer1UVTranslateV\",") outfile << "            Name: \"Layer1UVTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Layer1BaseV\"" || val[j + (i * valdif[i])] == "          Name: \"Layer1BaseV\",") outfile << "            Name: \"Layer1BaseV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"EmissionMaskVal\"," || val[j + (i * valdif[i])] == "          Name: \"EmissionMaskVal\"") outfile << "            Name: \"EmissionMaskVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ConstantColorSd0Val\"," || val[j + (i * valdif[i])] == "          Name: \"ConstantColorSd0Val\"") outfile << "            Name: \"ConstantColorSd0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ConstantColor1Val\"," || val[j + (i * valdif[i])] == "          Name: \"ConstantColor1Val\"") outfile << "            Name: \"ConstantColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ConstantColorSd1Val\"," || val[j + (i * valdif[i])] == "          Name: \"ConstantColorSd1Val\"") outfile << "            Name: \"ConstantColorSd1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ColorLerpValue\"" || val[j + (i * valdif[i])] == "          Name: \"ColorLerpValue\",") outfile << "            Name: \"ColorLerpValue\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"L1ConstantColor0Val\"," || val[j + (i * valdif[i])] == "          Name: \"L1ConstantColor0Val\"") outfile << "            Name: \"L1ConstantColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"L1AddColor0Val\"" || val[j + (i * valdif[i])] == "          Name: \"L1AddColor0Val\",") outfile << "            Name: \"L1AddColor0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"L1ConstantColor1Val\"," || val[j + (i * valdif[i])] == "          Name: \"L1ConstantColor1Val\"") outfile << "            Name: \"L1ConstantColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"L1AddColor1Val\"" || val[j + (i * valdif[i])] == "          Name: \"L1AddColor1Val\",") outfile << "            Name: \"L1AddColor1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"L1ConstantColorSd0Val\"," || val[j + (i * valdif[i])] == "          Name: \"L1ConstantColorSd0Val\"") outfile << "            Name: \"L1ConstantColorSd0Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"L1ConstantColorSd1Val\"," || val[j + (i * valdif[i])] == "          Name: \"L1ConstantColorSd1Val\"") outfile << "            Name: \"L1ConstantColorSd1Val\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Layer1OverLerpValue\"," || val[j + (i * valdif[i])] == "          Name: \"Layer1OverLerpValue\"") outfile << "            Name: \"Layer1OverLerpValue\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"NormalMapUVScaleU\"," || val[j + (i * valdif[i])] == "          Name: \"NormalMapUVScaleU\"") outfile << "            Name: \"NormalMapUVScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"NormalMapUVScaleV\"," || val[j + (i * valdif[i])] == "          Name: \"NormalMapUVScaleV\"") outfile << "            Name: \"NormalMapUVScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"LightTblIndex\"," || val[j + (i * valdif[i])] == "          Name: \"LightTblIndex\"") outfile << "            Name: \"LightTblIndex\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"LightMul\"," || val[j + (i * valdif[i])] == "          Name: \"LightMul\"") outfile << "            Name: \"LightMul\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"SpecularPower\"," || val[j + (i * valdif[i])] == "          Name: \"SpecularPower\"") outfile << "            Name: \"SpecularPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"SpecularScale\"," || val[j + (i * valdif[i])] == "          Name: \"SpecularScale\"") outfile << "            Name: \"SpecularScale\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"SphereMapColorVal\"," || val[j + (i * valdif[i])] == "          Name: \"SphereMapColorVal\"") outfile << "            Name: \"SphereMapColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"RimColorVal\"," || val[j + (i * valdif[i])] == "          Name: \"RimColorVal\"") outfile << "            Name: \"RimColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"RimPower\"," || val[j + (i * valdif[i])] == "          Name: \"RimPower\"") outfile << "            Name: \"RimPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"RimStrength\"," || val[j + (i * valdif[i])] == "          Name: \"RimStrength\"") outfile << "            Name: \"RimStrength\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Def0_OneMin1_FreCol\"," || val[j + (i * valdif[i])] == "          Name: \"Def0_OneMin1_FreCol\"") outfile << "            Name: \"Def0_OneMin1_FreCol\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"DistortionIntensity\"," || val[j + (i * valdif[i])] == "          Name: \"DistortionIntensity\"") outfile << "            Name: \"DistortionIntensity\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"Sin01\"," || val[j + (i * valdif[i])] == "          Name: \"Sin01\"") outfile << "            Name: \"Sin01\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ScaleUV\"," || val[j + (i * valdif[i])] == "          Name: \"ScaleUV\"") outfile << "            Name: \"ScaleUV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"EffectTexTranslateU\"" || val[j + (i * valdif[i])] == "          Name: \"EffectTexTranslateU\",") outfile << "            Name: \"EffectTexTranslateU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"EffectTexTranslateV\"" || val[j + (i * valdif[i])] == "          Name: \"EffectTexTranslateV\",") outfile << "            Name: \"EffectTexTranslateV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"EffectTexRotate\"" || val[j + (i * valdif[i])] == "          Name: \"EffectTexRotate\",") outfile << "            Name: \"EffectTexRotate\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"EffectTexScaleU\"," || val[j + (i * valdif[i])] == "          Name: \"EffectTexScaleU\"") outfile << "            Name: \"EffectTexScaleU\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"EffectTexScaleV\"," || val[j + (i * valdif[i])] == "          Name: \"EffectTexScaleV\"") outfile << "            Name: \"EffectTexScaleV\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"EffectColPower\"," || val[j + (i * valdif[i])] == "          Name: \"EffectColPower\"") outfile << "            Name: \"EffectColPower\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"OnGameEmissionVal\"," || val[j + (i * valdif[i])] == "          Name: \"OnGameEmissionVal\"") outfile << "            Name: \"OnGameEmissionVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ConstantColorVal\"," || val[j + (i * valdif[i])] == "          Name: \"ConstantColorVal\"") outfile << "            Name: \"ConstantColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ConstantAlpha\"," || val[j + (i * valdif[i])] == "          Name: \"ConstantAlpha\"") outfile << "            Name: \"ConstantAlpha\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"OnGameColorVal\"," || val[j + (i * valdif[i])] == "          Name: \"OnGameColorVal\"") outfile << "            Name: \"OnGameColorVal\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"OnGameAlpha\"," || val[j + (i * valdif[i])] == "          Name: \"OnGameAlpha\"") outfile << "            Name: \"OnGameAlpha\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"OutLineID\"" || val[j + (i * valdif[i])] == "          Name: \"OutLineID\",") outfile << "            Name: \"OutLineID\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "          Name: \"ProgID\"" || val[j + (i * valdif[i])] == "          Name: \"ProgID\",") outfile << "            Name: \"ProgID\",\n            Value_type: \"FixedValueTrack\",\n            Value: {\n";
                if (val[j + (i * valdif[i])] == "        }") outfile << "            }\n          }\n        ],\n";
            }
        }
        outfile << "        Vectors: [\n";
        for (int j = 0; j < coldif[i]; j++)
        {
            if (colvaltrunc[j + (i * coldif[i])] == "            X: ") outfile << "    " << colval[j + (i * coldif[i])] << endl;
            if (colvaltrunc[j + (i * coldif[i])] == "            Y: ") outfile << "    " << colval[j + (i * coldif[i])] << endl;
            if (colvaltrunc[j + (i * coldif[i])] == "            Z: ") outfile << "    " << colval[j + (i * coldif[i])] << endl;
            if (colval[j + (i * coldif[i])] == "        {") outfile << "          {\n";
            if (colval[j + (i * coldif[i])] == "        },") outfile << "            }\n          },\n";
            if (colval[j + (i * coldif[i])] == "          }") outfile << "              }\n";
            if (colval[j + (i * coldif[i])] == "          Color: {") outfile << "              Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"ConstantColor0\",") outfile << "            Name: \"ConstantColor0\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"ConstantColorSd0\",") outfile << "            Name: \"ConstantColorSd0\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"ConstantColor1\",") outfile << "            Name: \"ConstantColor1\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"ConstantColorSd1\",") outfile << "            Name: \"ConstantColorSd1\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"L1ConstantColor0\",") outfile << "            Name: \"L1ConstantColor0\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"L1AddColor0\",") outfile << "            Name: \"L1AddColor0\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"L1ConstantColor1\",") outfile << "            Name: \"L1ConstantColor1\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"L1AddColor1\",") outfile << "            Name: \"L1AddColor1\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"L1ConstantColorSd0\",") outfile << "            Name: \"L1ConstantColorSd0\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"L1ConstantColorSd1\",") outfile << "            Name: \"L1ConstantColorSd1\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"DeepShadowColor\",") outfile << "            Name: \"DeepShadowColor\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"SpecularColor\",") outfile << "            Name: \"SpecularColor\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"SphereMapColor\",") outfile << "            Name: \"SphereMapColor\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"XimColor\",") outfile << "            Name: \"RimColor\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"XimColorShadow\",") outfile << "            Name: \"RimColorShadow\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"EffectColor01\",") outfile << "            Name: \"EffectColor01\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"ConstantColor\",") outfile << "            Name: \"ConstantColor\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"OnYameColor\",") outfile << "            Name: \"OnGameColor\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "          Name: \"OutLineCol\",") outfile << "            Name: \"OutLineCol\",\n            Value_type: \"FixedVectorTrack\",\n            Value: {\n";
            if (colval[j + (i * coldif[i])] == "        }") outfile << "            }\n          }\n        ]\n";
        }
        if (i < (matcount - 1)) outfile << "      },\n";
        if (i == (matcount - 1)) outfile << "      }\n    ]\n  },\n";
    }
    outfile << "  Triggers: {\n    Triggers: [\n      {\n        Name: \"System/SetBoolParameter\",\n        FrameEnd: " << framecount << ",\n        Parameter: {\n        }\n      },\n      {\n        Name: \"Sound/Wwise\",\n        FrameStart: 11,\n        FrameEnd: 12,\n        Parameter: {\n        }\n      }\n    ]\n  }\n}\n";
    outfile.close();
    ifstream infile3("deleteme.json");
    ofstream outfile2(outpath + ".json");
    infile.close();
    infile2.close();
    for (int i = 0; i < 100000; i++)
    {
        getline(infile3, filecontent[i], '\n');
    }
    if (looptrue == 'y')
    {
        for (int i = 0; i < 8; i++)
        {
            outfile2 << filecontent[i] << endl;
        }
        for (int i = 8; i < 100000; i++)
        {
            if (filecontent[i] == "        Rotate_type: \"DynamicRotationTrack\","
                && filecontent[i + 4] == filecontent[i + 9]
                && filecontent[i + 9] == filecontent[i + 14]
                && filecontent[i + 14] == filecontent[i + 19]
                && filecontent[i + 19] == filecontent[i + 24]
                && filecontent[i + 5] == filecontent[i + 10]
                && filecontent[i + 10] == filecontent[i + 15]
                && filecontent[i + 15] == filecontent[i + 20]
                && filecontent[i + 20] == filecontent[i + 25]
                && filecontent[i + 6] == filecontent[i + 11]
                && filecontent[i + 11] == filecontent[i + 16]
                && filecontent[i + 16] == filecontent[i + 21]
                && filecontent[i + 21] == filecontent[i + 26])
            {
                outfile2 << filecontent[i - 10] << endl << filecontent[i - 9] << endl << filecontent[i - 8] << endl << filecontent[i - 7] << endl << filecontent[i - 6] << endl << filecontent[i - 5] << endl << filecontent[i - 4] << endl << filecontent[i - 3] << endl << filecontent[i - 2] << endl << filecontent[i - 1] << endl << "        Rotate_type: \"FixedRotationTrack\",\n        Rotate: {\n          Value: {\n" << filecontent[i + 4] << endl << filecontent[i + 5] << endl << filecontent[i + 6] << "\n          }\n        },\n";
            }
            if (filecontent[i] == "        Translate_type: \"DynamicVectorTrack\","
                && filecontent[i + 4] == filecontent[i + 9]
                && filecontent[i + 9] == filecontent[i + 14]
                && filecontent[i + 14] == filecontent[i + 19]
                && filecontent[i + 19] == filecontent[i + 24]
                && filecontent[i + 5] == filecontent[i + 10]
                && filecontent[i + 10] == filecontent[i + 15]
                && filecontent[i + 15] == filecontent[i + 20]
                && filecontent[i + 20] == filecontent[i + 25]
                && filecontent[i + 6] == filecontent[i + 11]
                && filecontent[i + 11] == filecontent[i + 16]
                && filecontent[i + 16] == filecontent[i + 21]
                && filecontent[i + 21] == filecontent[i + 26])
            {
                if (filecontent[i + (5 * framecount) + 7] != "  },") outfile2 << "        Translate_type: \"FixedVectorTrack\",\n        Translate: {\n          Value: {\n" << filecontent[i + 4] << endl << filecontent[i + 5] << endl << filecontent[i + 6] << endl << "          }\n        }\n      },\n";
                else
                {
                    outfile2 << "        Translate_type: \"FixedVectorTrack\",\n        Translate: {\n          Value: {\n" << filecontent[i + 4] << endl << filecontent[i + 5] << endl << filecontent[i + 6] << endl << "          }\n        }\n      }\n    ]\n  },\n";
                }
            }
            if (filecontent[i] == "        Rotate_type: \"DynamicRotationTrack\","
                && (filecontent[i + 4] != filecontent[i + 9]
                    || filecontent[i + 9] != filecontent[i + 14]
                    || filecontent[i + 14] != filecontent[i + 19]
                    || filecontent[i + 19] != filecontent[i + 24]
                    || filecontent[i + 5] != filecontent[i + 10]
                    || filecontent[i + 10] != filecontent[i + 15]
                    || filecontent[i + 15] != filecontent[i + 20]
                    || filecontent[i + 20] != filecontent[i + 25]
                    || filecontent[i + 6] != filecontent[i + 11]
                    || filecontent[i + 11] != filecontent[i + 16]
                    || filecontent[i + 16] != filecontent[i + 21]
                    || filecontent[i + 21] != filecontent[i + 26]))
            {
                outfile2 << filecontent[i - 10] << endl << filecontent[i - 9] << endl << filecontent[i - 8] << endl << filecontent[i - 7] << endl << filecontent[i - 6] << endl << filecontent[i - 5] << endl << filecontent[i - 4] << endl << filecontent[i - 3] << endl << filecontent[i - 2] << endl << filecontent[i - 1] << endl << "        Rotate_type: \"DynamicRotationTrack\",\n        Rotate: {\n          Values: [\n";
                for (int j = i + 3; j < (i + (5 * framecount) + 5); j++)
                {
                    outfile2 << filecontent[j] << endl;
                }
            }
            if (filecontent[i] == "        Translate_type: \"DynamicVectorTrack\","
                && (filecontent[i + 4] != filecontent[i + 9]
                    || filecontent[i + 9] != filecontent[i + 14]
                    || filecontent[i + 14] != filecontent[i + 19]
                    || filecontent[i + 19] != filecontent[i + 24]
                    || filecontent[i + 5] != filecontent[i + 10]
                    || filecontent[i + 10] != filecontent[i + 15]
                    || filecontent[i + 15] != filecontent[i + 20]
                    || filecontent[i + 20] != filecontent[i + 25]
                    || filecontent[i + 6] != filecontent[i + 11]
                    || filecontent[i + 11] != filecontent[i + 16]
                    || filecontent[i + 16] != filecontent[i + 21]
                    || filecontent[i + 21] != filecontent[i + 26]))
            {
                outfile2 << "        Translate_type: \"DynamicVectorTrack\",\n        Translate: {\n          Values: [\n";
                if (filecontent[i + (5 * framecount) + 7] != "  },")
                {
                    for (int j = i + 3; j < (i + (5 * framecount) + 6); j++)
                    {
                        outfile2 << filecontent[j] << endl;
                    }
                }
                else
                {
                    for (int j = i + 3; j < (i + (5 * framecount) + 8); j++)
                    {
                        outfile2 << filecontent[j] << endl;
                    }
                }
            }
            if (filecontent[i] == "  Materials: {")
            {
                for (int j = i; j < (i + 10000); j++)
                {
                    outfile2 << filecontent[j] << endl;
                }
            }
        }
    }
    if (looptrue == 'n')
    {
        for (int i = 0; i < 7; i++)
        {
            outfile2 << filecontent[i] << endl;
        }
        for (int i = 7; i < 100000; i++)
        {
            if (filecontent[i] == "        Rotate_type: \"DynamicRotationTrack\","
                && filecontent[i + 4] == filecontent[i + 9]
                && filecontent[i + 9] == filecontent[i + 14]
                && filecontent[i + 14] == filecontent[i + 19]
                && filecontent[i + 19] == filecontent[i + 24]
                && filecontent[i + 5] == filecontent[i + 10]
                && filecontent[i + 10] == filecontent[i + 15]
                && filecontent[i + 15] == filecontent[i + 20]
                && filecontent[i + 20] == filecontent[i + 25]
                && filecontent[i + 6] == filecontent[i + 11]
                && filecontent[i + 11] == filecontent[i + 16]
                && filecontent[i + 16] == filecontent[i + 21]
                && filecontent[i + 21] == filecontent[i + 26])
            {
                outfile2 << filecontent[i - 10] << endl << filecontent[i - 9] << endl << filecontent[i - 8] << endl << filecontent[i - 7] << endl << filecontent[i - 6] << endl << filecontent[i - 5] << endl << filecontent[i - 4] << endl << filecontent[i - 3] << endl << filecontent[i - 2] << endl << filecontent[i - 1] << endl << "        Rotate_type: \"FixedRotationTrack\",\n        Rotate: {\n          Value: {\n" << filecontent[i + 4] << endl << filecontent[i + 5] << endl << filecontent[i + 6] << "\n          }\n        },\n";
            }
            if (filecontent[i] == "        Translate_type: \"DynamicVectorTrack\","
                && filecontent[i + 4] == filecontent[i + 9]
                && filecontent[i + 9] == filecontent[i + 14]
                && filecontent[i + 14] == filecontent[i + 19]
                && filecontent[i + 19] == filecontent[i + 24]
                && filecontent[i + 5] == filecontent[i + 10]
                && filecontent[i + 10] == filecontent[i + 15]
                && filecontent[i + 15] == filecontent[i + 20]
                && filecontent[i + 20] == filecontent[i + 25]
                && filecontent[i + 6] == filecontent[i + 11]
                && filecontent[i + 11] == filecontent[i + 16]
                && filecontent[i + 16] == filecontent[i + 21]
                && filecontent[i + 21] == filecontent[i + 26])
            {
                if (filecontent[i + (5 * framecount) + 7] != "  },") outfile2 << "        Translate_type: \"FixedVectorTrack\",\n        Translate: {\n          Value: {\n" << filecontent[i + 4] << endl << filecontent[i + 5] << endl << filecontent[i + 6] << endl << "          }\n        }\n      },\n";
                else
                {
                    outfile2 << "        Translate_type: \"FixedVectorTrack\",\n        Translate: {\n          Value: {\n" << filecontent[i + 4] << endl << filecontent[i + 5] << endl << filecontent[i + 6] << endl << "          }\n        }\n      }\n    ]\n  },\n";
                }
            }
            if (filecontent[i] == "        Rotate_type: \"DynamicRotationTrack\","
                && (filecontent[i + 4] != filecontent[i + 9]
                || filecontent[i + 9] != filecontent[i + 14]
                || filecontent[i + 14] != filecontent[i + 19]
                || filecontent[i + 19] != filecontent[i + 24]
                || filecontent[i + 5] != filecontent[i + 10]
                || filecontent[i + 10] != filecontent[i + 15]
                || filecontent[i + 15] != filecontent[i + 20]
                || filecontent[i + 20] != filecontent[i + 25]
                || filecontent[i + 6] != filecontent[i + 11]
                || filecontent[i + 11] != filecontent[i + 16]
                || filecontent[i + 16] != filecontent[i + 21]
                || filecontent[i + 21] != filecontent[i + 26]))
            {
                outfile2 << filecontent[i - 10] << endl << filecontent[i - 9] << endl << filecontent[i - 8] << endl << filecontent[i - 7] << endl << filecontent[i - 6] << endl << filecontent[i - 5] << endl << filecontent[i - 4] << endl << filecontent[i - 3] << endl << filecontent[i - 2] << endl << filecontent[i - 1] << endl << "        Rotate_type: \"DynamicRotationTrack\",\n        Rotate: {\n          Values: [\n";
                for (int j = i + 3; j < (i + (5 * framecount) + 5); j++)
                {
                    outfile2 << filecontent[j] << endl;
                }
            }
            if (filecontent[i] == "        Translate_type: \"DynamicVectorTrack\","
                && (filecontent[i + 4] != filecontent[i + 9]
                    || filecontent[i + 9] != filecontent[i + 14]
                    || filecontent[i + 14] != filecontent[i + 19]
                    || filecontent[i + 19] != filecontent[i + 24]
                    || filecontent[i + 5] != filecontent[i + 10]
                    || filecontent[i + 10] != filecontent[i + 15]
                    || filecontent[i + 15] != filecontent[i + 20]
                    || filecontent[i + 20] != filecontent[i + 25]
                    || filecontent[i + 6] != filecontent[i + 11]
                    || filecontent[i + 11] != filecontent[i + 16]
                    || filecontent[i + 16] != filecontent[i + 21]
                    || filecontent[i + 21] != filecontent[i + 26]))
            {
                outfile2 << "        Translate_type: \"DynamicVectorTrack\",\n        Translate: {\n          Values: [\n";
                if (filecontent[i + (5 * framecount) + 7] != "  },")
                {
                    for (int j = i + 3; j < (i + (5 * framecount) + 6); j++)
                    {
                        outfile2 << filecontent[j] << endl;
                    }
                }
                else
                {
                    for (int j = i + 3; j < (i + (5 * framecount) + 8); j++)
                    {
                        outfile2 << filecontent[j] << endl;
                    }
                }
            }
            if (filecontent[i] == "  Materials: {")
            {
                for (int j = i; j < (i + 10000); j++)
                {
                    outfile2 << filecontent[j] << endl;
                }
            }
        }
    }
    cout << "Thank you for singing in the chorus of souls!\nIf you are adding back a removed Pokemon,\nthen the colors of that Pokemon are now weaving into a spire of flame.\n";
    infile3.close();
    outfile2.close();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

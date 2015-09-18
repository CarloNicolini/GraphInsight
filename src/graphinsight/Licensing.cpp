/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include "Licensing.h"
#include "QDialog"
#include "ui_Activate.h"
#include "QFile"
#include <QCryptographicHash>
#include "QUtils.h"

/**
 * @brief Licensing::Licensing
 */
Licensing::Licensing()
{
}

/**
 * @brief Licensing::Licensing
 * @param appPath
 */
Licensing::Licensing(QString appPath)
{

   this->appPath = appPath;

   xorKey = (unsigned char *)malloc(512);
   xorKey[0] = 58;
   xorKey[1] = 135;
   xorKey[2] = 164;
   xorKey[3] = 97;
   xorKey[4] = 236;
   xorKey[5] = 168;
   xorKey[6] = 0;
   xorKey[7] = 220;
   xorKey[8] = 213;
   xorKey[9] = 8;
   xorKey[10] = 66;
   xorKey[11] = 139;
   xorKey[12] = 195;
   xorKey[13] = 167;
   xorKey[14] = 122;
   xorKey[15] = 140;
   xorKey[16] = 186;
   xorKey[17] = 59;
   xorKey[18] = 196;
   xorKey[19] = 39;
   xorKey[20] = 9;
   xorKey[21] = 19;
   xorKey[22] = 234;
   xorKey[23] = 40;
   xorKey[24] = 146;
   xorKey[25] = 102;
   xorKey[26] = 127;
   xorKey[27] = 163;
   xorKey[28] = 244;
   xorKey[29] = 11;
   xorKey[30] = 54;
   xorKey[31] = 55;
   xorKey[32] = 47;
   xorKey[33] = 14;
   xorKey[34] = 93;
   xorKey[35] = 234;
   xorKey[36] = 114;
   xorKey[37] = 61;
   xorKey[38] = 41;
   xorKey[39] = 195;
   xorKey[40] = 223;
   xorKey[41] = 114;
   xorKey[42] = 173;
   xorKey[43] = 177;
   xorKey[44] = 60;
   xorKey[45] = 91;
   xorKey[46] = 214;
   xorKey[47] = 97;
   xorKey[48] = 234;
   xorKey[49] = 120;
   xorKey[50] = 22;
   xorKey[51] = 44;
   xorKey[52] = 54;
   xorKey[53] = 132;
   xorKey[54] = 45;
   xorKey[55] = 27;
   xorKey[56] = 186;
   xorKey[57] = 147;
   xorKey[58] = 195;
   xorKey[59] = 64;
   xorKey[60] = 115;
   xorKey[61] = 152;
   xorKey[62] = 52;
   xorKey[63] = 94;
   xorKey[64] = 63;
   xorKey[65] = 141;
   xorKey[66] = 62;
   xorKey[67] = 157;
   xorKey[68] = 232;
   xorKey[69] = 3;
   xorKey[70] = 129;
   xorKey[71] = 200;
   xorKey[72] = 118;
   xorKey[73] = 201;
   xorKey[74] = 248;
   xorKey[75] = 73;
   xorKey[76] = 85;
   xorKey[77] = 241;
   xorKey[78] = 88;
   xorKey[79] = 107;
   xorKey[80] = 172;
   xorKey[81] = 111;
   xorKey[82] = 3;
   xorKey[83] = 152;
   xorKey[84] = 215;
   xorKey[85] = 251;
   xorKey[86] = 249;
   xorKey[87] = 132;
   xorKey[88] = 232;
   xorKey[89] = 20;
   xorKey[90] = 120;
   xorKey[91] = 30;
   xorKey[92] = 47;
   xorKey[93] = 185;
   xorKey[94] = 169;
   xorKey[95] = 28;
   xorKey[96] = 141;
   xorKey[97] = 190;
   xorKey[98] = 25;
   xorKey[99] = 134;
   xorKey[100] = 56;
   xorKey[101] = 203;
   xorKey[102] = 93;
   xorKey[103] = 27;
   xorKey[104] = 31;
   xorKey[105] = 237;
   xorKey[106] = 144;
   xorKey[107] = 223;
   xorKey[108] = 12;
   xorKey[109] = 82;
   xorKey[110] = 30;
   xorKey[111] = 204;
   xorKey[112] = 201;
   xorKey[113] = 135;
   xorKey[114] = 114;
   xorKey[115] = 215;
   xorKey[116] = 216;
   xorKey[117] = 216;
   xorKey[118] = 27;
   xorKey[119] = 84;
   xorKey[120] = 136;
   xorKey[121] = 180;
   xorKey[122] = 98;
   xorKey[123] = 232;
   xorKey[124] = 232;
   xorKey[125] = 163;
   xorKey[126] = 106;
   xorKey[127] = 143;
   xorKey[128] = 7;
   xorKey[129] = 180;
   xorKey[130] = 107;
   xorKey[131] = 111;
   xorKey[132] = 210;
   xorKey[133] = 130;
   xorKey[134] = 121;
   xorKey[135] = 106;
   xorKey[136] = 170;
   xorKey[137] = 28;
   xorKey[138] = 14;
   xorKey[139] = 190;
   xorKey[140] = 228;
   xorKey[141] = 2;
   xorKey[142] = 49;
   xorKey[143] = 33;
   xorKey[144] = 212;
   xorKey[145] = 129;
   xorKey[146] = 248;
   xorKey[147] = 19;
   xorKey[148] = 53;
   xorKey[149] = 147;
   xorKey[150] = 197;
   xorKey[151] = 244;
   xorKey[152] = 206;
   xorKey[153] = 159;
   xorKey[154] = 109;
   xorKey[155] = 133;
   xorKey[156] = 109;
   xorKey[157] = 167;
   xorKey[158] = 182;
   xorKey[159] = 82;
   xorKey[160] = 100;
   xorKey[161] = 99;
   xorKey[162] = 221;
   xorKey[163] = 94;
   xorKey[164] = 57;
   xorKey[165] = 49;
   xorKey[166] = 3;
   xorKey[167] = 94;
   xorKey[168] = 180;
   xorKey[169] = 235;
   xorKey[170] = 181;
   xorKey[171] = 233;
   xorKey[172] = 241;
   xorKey[173] = 159;
   xorKey[174] = 10;
   xorKey[175] = 0;
   xorKey[176] = 47;
   xorKey[177] = 125;
   xorKey[178] = 85;
   xorKey[179] = 46;
   xorKey[180] = 113;
   xorKey[181] = 70;
   xorKey[182] = 154;
   xorKey[183] = 78;
   xorKey[184] = 64;
   xorKey[185] = 217;
   xorKey[186] = 180;
   xorKey[187] = 151;
   xorKey[188] = 148;
   xorKey[189] = 179;
   xorKey[190] = 185;
   xorKey[191] = 122;
   xorKey[192] = 45;
   xorKey[193] = 20;
   xorKey[194] = 198;
   xorKey[195] = 21;
   xorKey[196] = 118;
   xorKey[197] = 250;
   xorKey[198] = 15;
   xorKey[199] = 30;
   xorKey[200] = 40;
   xorKey[201] = 82;
   xorKey[202] = 120;
   xorKey[203] = 162;
   xorKey[204] = 210;
   xorKey[205] = 228;
   xorKey[206] = 8;
   xorKey[207] = 126;
   xorKey[208] = 132;
   xorKey[209] = 246;
   xorKey[210] = 115;
   xorKey[211] = 199;
   xorKey[212] = 29;
   xorKey[213] = 32;
   xorKey[214] = 167;
   xorKey[215] = 67;
   xorKey[216] = 170;
   xorKey[217] = 198;
   xorKey[218] = 1;
   xorKey[219] = 126;
   xorKey[220] = 66;
   xorKey[221] = 209;
   xorKey[222] = 142;
   xorKey[223] = 154;
   xorKey[224] = 52;
   xorKey[225] = 242;
   xorKey[226] = 166;
   xorKey[227] = 17;
   xorKey[228] = 33;
   xorKey[229] = 32;
   xorKey[230] = 35;
   xorKey[231] = 72;
   xorKey[232] = 56;
   xorKey[233] = 157;
   xorKey[234] = 113;
   xorKey[235] = 229;
   xorKey[236] = 177;
   xorKey[237] = 44;
   xorKey[238] = 249;
   xorKey[239] = 171;
   xorKey[240] = 75;
   xorKey[241] = 195;
   xorKey[242] = 233;
   xorKey[243] = 60;
   xorKey[244] = 215;
   xorKey[245] = 240;
   xorKey[246] = 229;
   xorKey[247] = 51;
   xorKey[248] = 168;
   xorKey[249] = 163;
   xorKey[250] = 66;
   xorKey[251] = 211;
   xorKey[252] = 230;
   xorKey[253] = 38;
   xorKey[254] = 54;
   xorKey[255] = 192;
   xorKey[256] = 148;

}

/**
 * @brief Licensing::~Licensing
 */
Licensing::~Licensing()
{
}

QByteArray Licensing::encode(int salt, QByteArray v)
{  QByteArray b;
   for(int i = 0; i< v.size(); i++)
   {  b.append(v.at(i) + xorKey[(salt+i) % 255]);
   }

   return b;
}

QByteArray Licensing::decode(int salt, QByteArray v)
{  QByteArray b;



   for(int i = 0; i< v.size(); i++)
   {  b.append(v.at(i)- xorKey[(salt+i) % 255]);
   }

   return b;
}

bool Licensing::readFromFile()
{

   QFile f(QString(appPath).append("/../Resources/license"));

   if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
      return false;

   QStringList l = QString(decode(123,QByteArray::fromBase64(f.readAll()))).split(";");
   if(l.size()!= 2)
      return false;

   this->eMail = l.at(0).toLocal8Bit().constData();
   this->productKey = l.at(1).toLocal8Bit().constData();

   return true;
}


bool Licensing::validate()
{  QCryptographicHash hash(QCryptographicHash::Md5);
   hash.addData(encode(321,QString("BETA;").append(this->eMail).toAscii()));

   QString trueProductKey = QString(hash.result().toHex()).left(12);

//   printf("true product key: %s\n", trueProductKey.toAscii().data());

   return this->productKey.compare(trueProductKey) == 0;

}

bool Licensing::writeToFile()
{  QFile f(QString(appPath).append("/../Resources/license"));

   printf("path: %s\n", QString(appPath).append("/../Resources/license").toAscii().data());

   if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
      return false;

   f.write(encode(123,this->eMail.append(";").append(this->productKey).toAscii()).toBase64());
   f.close();

   return true;
}

bool Licensing::activate()
{  bool ret;

   if(!readFromFile())
   {

      QDialog *w2 = new QDialog;
      Ui_ActivateDialog d;
      d.setupUi(w2);
      w2->setWindowFlags(Qt::WindowStaysOnTopHint );//Qt::SplashScreen
      w2->exec();

      this->eMail = d.lineEdit_2->text();
      this->productKey = d.lineEdit->text();

      if(validate())
      {  writeToFile();
         ret = true;
      }
      else
      {  ret = false;
      }

   }
   else
   {  ret = validate();
   }

   return ret; // never reached
}

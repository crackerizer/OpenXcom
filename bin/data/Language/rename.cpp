#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

int main()
{
	int row = 24;
	int col = 16;
	std::wstring str = L"!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~¡¢£¤¥¦§¨©ª«¬®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖŐŰÙÚÛÜÝÞŸßàáâãäåæçèéêëìíîïðñòóôõöőűùúûüýþÿФИСВУАПРШОЛДЬТЩЗЙКЫЕГМЦЧНЯфисвуапршолдьтщзйкыегмцчнябБжЖхХъЪэЭюЮĆĘęąŁćłĄŚśźżŻŹŃńĂăȘȚșțČĎĚŇŘŠŤŮŽčďěňřšťůžЄєŒœіІїЇøØĞŞİğşıΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩαβγδεζηθικλμνξοπρστυφχψωΆΈΉΊΌΎΏάέήίόύώςΐϊĹĽŔĺľŕ∞Ёё";
	std::string fileNameTemplate = "FontSmall [www.imagesplitter.net]-{row}-{col}";
	std::string ext = ".png";
	int strpos = 0;
	int strlen = str.length();
	std::ostringstream cs;
	
	for(int rc = 0; rc < row; rc++)
		for(int cc = 0; cc < col; cc++)
		{
			if(strpos >= strlen)
				break;
				
			long strn = (long)str[strpos];
			std::string fileName = 	fileNameTemplate;						
						
			cs << std::dec;			
			cs << rc;
			fileName.replace(fileName.find("{row}"),5 , cs.str());
			cs.str("");
			cs << cc;
			fileName.replace(fileName.find("{col}"),5 , cs.str());
			cs.str("");
			
			fileName += ext;			
			cs << std::hex << strn << ".png";
			
			std::cout << "Rename '" << fileName << "' to '" << cs.str() << "'" << std::endl;						
					
			std::string cmd = "mv \"";
			cmd += fileName + "\" \"";
			cmd += cs.str() + "\"";
			
			//std::cout << cmd << std::endl;
			system(cmd.c_str());
			
			cs.str("");
			
			strpos++;
		}
	
	return 0;
}

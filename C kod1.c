
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000
void decodeText(char* text);
int main() {
	FILE* file;
	char text[MAX_SIZE];
	char encryptedText[MAX_SIZE];
	file = fopen("G:\\odevdenemesi\\deneme.txt", "r");//dosyayi okuma modunda actim
	fgets(text, MAX_SIZE, file);//dosyadan sifreli metni oku
	strcpy(encryptedText, text);//sifreli metni ayri degiskende sakla
	fclose(file);//dosyayi kapa
	decodeText(text);//sifreli metni coz
	printf("%s", text);//cosulmus metni ekrana yaz
	file = fopen("G:\\odevdenemesi\\deneme.txt", "w");//dosyayi yazma modunda ac
	fprintf(file, "%s\n", encryptedText);//sifreli metni dısyaya yaz
	fprintf(file, "%s", text);//cozulmus metni dosyaya yaz
	fclose(file);//dosyayi kapat
	return 0;
}
void decodeText(char* text) {
	int length = strlen(text);//text dosyamin uzunlugunu aldim
	int outputIndex = 0;
	char decodedText[MAX_SIZE];
	//sifreli metni cozme islemim icin for döngüsü kullaniyorum
	for (int i = 0; i < length; i++) {
		//karakterin rakam olup olmadigini kontrol ediyorum
		if (text[i] >= '0' && text[i] <= '9') {
			int count = text[i] - '0';
			//tekrarlayan karakteri cozulmus metne eklemek için for dongusu kullandim
			for (int j = 0; j < count; j++) {
				//cikti boyutu max_size sinirlarini asarsa donguden cik
				if (outputIndex >= MAX_SIZE - 1) {
					break;
				}
				//tekrarlayan karakteri cozulen metnime ekliyorum
				decodedText[outputIndex++] = text[i - 1];
			}
		}
	}
	//cozulen metnin sonunu bilebilmek icin null ekliyorum
	decodedText[outputIndex] = '\0';
	//cozulen metnimi asil metnime kopyaliyorum
	strcpy(text, decodedText);
}
#include <stdio.h>
#define help printf("Введите команду\n1: q выход из программы\n2: s установка бита, введите номер бита от 0 до 7 и значение 1-истина, 2-Ложь\n3: g получение значения бита, введите номер бита значения которого должно быть выведено на экран\n4: m для вывода меню\n ")

int main() {
  char bitField = 0; char command;
  int numBit; int value;
  help;
  while(1){
    scanf("%c", &command);
    if (command == 's'){
      printf("Введите номер бита: "); scanf("%d", &numBit);
      printf("Введите значение для установки 1-истина 2-ложь: "); scanf("%d", &value);
      bitField = (value == 1) ? (bitField | 1 << numBit) : (bitField & ~(1 << numBit));
      printf("Бит с номером %d установлен в %d\n", numBit, (bitField & 1 << numBit ? 1 : 0) );
    }
    if (command == 'g'){
      printf("Введите номер бита: "); scanf("%d", &numBit);
      printf("Бит с номером %d равен %d\n", numBit, getBit(bitField, numBit));
    }
    if (command == 'm') {
      help;
    }
    if (command == 'q'){
      return 0;
    }
  }
  return 0;
}

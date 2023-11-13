 #include <stdio.h>
int main()
{
  
   char str[100];
   int chose = 0;
   int key = 0;
   while (1)
   {
      printf("\n--------------------------------------------------------------\n");
      printf("**************************************************************\n");
      printf("\nChose:  1-Encryption   2- Decryption \n");
      scanf("%d", &chose);

      switch (chose)
      {
      case 1:
         printf("Enter the message:");
         scanf(" %[^\n]", &str);
         printf("Enter the key:");
         scanf("%d", &key);
         encr(str, key);
         break;
      case 2:
         printf("Enter the message:");
         scanf(" %[^\n]", &str);
         printf("Enter the key:");
         scanf("%d", &key);
         decr(str, key);
         break;

      default:
         printf("Wrong choice");
         break;
      }
   }

   return 0;
}



void encr(char *str, int key)
{
   for (int i = 0; str[i]; i++)
   {
      if (str[i] >= 'a' && str[i] <= 'z')
      {
         str[i] = (str[i] - 'a' + key) % 26 + 'a';
         printf("%c", str[i]);
      }
      else if (str[i] >= 'A' && str[i] <= 'Z')
      {
         str[i] = (str[i] - 'A' + key) % 26 + 'A';
         printf("%c", str[i]);
      }
      else
      {
         printf("\nThe message isn't character\n");
      }
   }
}

void decr(char *str, int key)
{
   for (int i = 0; str[i]; i++)
   {
      if (str[i] >= 'a' && str[i] <= 'z')
      {
         // Adjust the decryption formula
         str[i] = (str[i] - 'a' - key + 26);
         if (str[i] < 0)
         {
            str[i] = (str[i] * (-1)) % 26 + 'a';
         }
         else
         {
            str[i] = str[i] % 26 + 'a';
         }

         printf("%c", str[i]);
      }
      else if (str[i] >= 'A' && str[i] <= 'Z')
      {
         // Adjust the decryption formula
         str[i] = (str[i] - 'A' - key + 26);

         if (str[i] < 0)
         {
            str[i] = (str[i] * (-1)) % 26 + 'A';
         }
         else
         {
            str[i] = str[i] % 26 + 'A';
         }

         printf("%c", str[i]);
      }
      else
      {
         // Handle non-alphabetic characters
         printf("\nThe message isn't character\n");
      }
   }
}

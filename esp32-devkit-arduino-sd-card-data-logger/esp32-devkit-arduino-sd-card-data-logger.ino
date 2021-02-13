#include "FS.h"
#include "SD.h"
#include <SPI.h>

#define CS_PIN 22

void setup()
{
  Serial.begin(115200);

  // Initialize SD card
  if (!SD.begin(CS_PIN))
  {
    Serial.println("SD card mount failed");
    return;
  }
  else
  {
    Serial.println("SD card mounted");
  }
  
  // Get SD card type
  uint8_t card_type = SD.cardType();
  if (card_type == CARD_NONE)
  {
    Serial.println("No SD card attached");
    return;
  }
  // Print SD card type
  Serial.print("SD card type: ");
  if (card_type == CARD_MMC)
    Serial.println("MMC");
  else if (card_type == CARD_SD)
    Serial.println("SDSC");
  else if (card_type == CARD_SDHC)
    Serial.println("SDHC");
  else
    Serial.println("UNKNOWN");

  // Print SD card size
  Serial.printf("SD card size: %llu MB\n", SD.cardSize() / (1024 * 1024));
  Serial.printf("Total space: %llu MB\n", SD.totalBytes() / (1024 * 1024));
  Serial.printf("Used space: %llu MB\n", SD.usedBytes() / (1024 * 1024));

  // If the data.csv file doesn't exist, then create a file on the SD card and write the data labels
  File file = SD.open("/data.csv");
  if (!file)
  {
    Serial.println("File doens't exist. Creating file...");
    writeFile(SD, "/data.csv", "ID,Data\r\n");
  }
  else
  {
    Serial.println("File already exists");  
  }
  file.close();

  
  for (int i = 0; i < 5; i++)
  {
    String sample = String(i) + "," + String(i*5) + "\r\n";
    appendFile(SD, "/data.csv", sample.c_str());
    delay(1000);
  }
}

void loop()
{
}

void writeFile(fs::FS &fs, const char *path, const char *message)
{
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file)
  {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.print(message))
  {
    Serial.println("File written");
  } 
  else
  {
    Serial.println("Write failed");
  }
  file.close();
}

void appendFile(fs::FS &fs, const char *path, const char *message)
{
  Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file)
  {
    Serial.println("Failed to open file for appending");
    return;
  }
  if (file.print(message))
  {
    Serial.println("Message appended");
  }
  else
  {
    Serial.println("Append failed");
  }
  file.close();
}

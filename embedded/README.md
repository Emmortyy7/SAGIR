Kodlarda yapılan değişikllikler notes/changelog.txt ye yazıyor. Yapılacak olanlar notes/TODO.txt de yazıyor.

NOT : Her .h dosyasına board.h olucak ve eğer varsa özel ayarları config'den ayrı ayrı dosyalar ile çekilmiş olucak
Kod düzeni buna bağlı olucak.

NOT : Eğer mikroişlemci değişirse ona ait linker dosyası eklenip ona özel makefile yapılması lazım.

NOT : Yeni bir peripheral eklendiği zaman Core/Inc içinden conf dosyasını bulup enable flagini aktif et.

NOT : Yeni bir peripheral ekleneceği zaman hal altında bulunan o peripherala ait driver dosyasını makefile a ekle

NOT : Herhangi bir .c dosyası makefile a eklenmek zorunda 

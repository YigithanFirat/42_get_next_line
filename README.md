*This project has been created as part of the 42 cirriculum by yfirat.*

# GET_NEXT_LINE

## DESCRIPTION

**GET_NEXT_LINE** bir dosya tanımlayıcısından (file descriptor) okunan metinleri satır satır döndüren bir fonksiyondur. Bu projede ki temel amaçlardan biri statik değişkenleri anlamak, (static variables) bellek yönetimini dinamik şekilde kontrol edebilmektir.

Fonksiyon her çağrıldığında belirtilen dosyadan `\n` karakterine olan kısmı sızıntı olmadan geri döndürür.

### Core Logic & Functions

Projenin ana mantığı static buffer değişkeni üzerinden veriyi işlemeke üzerine kuruludur. Dosyada bulunan fonksiyonlar ve işlevleri şöyledir:

- `read_from_file` : Belirtilen dosyadan satır sonu (`\n`) veya dosya sonuna kadar (EOF) BUFFER_SIZE kadar veri okur. Okunana her parça statik olarak değişkene eklenerek verinin birikmesini sağlar.

- `get_current_line` : Statik değişkende biriken verinin başından başlayarak `\n` karakterine kadar (o kısım dahil olmak üzere) ayıklar ve yeni bellek alanına kopyalayarak geri döndürür. Bu kullanıcının fonksiyonu çağırdığında elde edeceği mevcut satırdır.

- `update_state_buffer` : Bir satır kullanıcıya döndürdükten sonra statik değişkende kalan veriyi (bir sonraki satırın başlangıcı) günceller. Kullanılan kısmı serbest bırakır ve kalan kısmı bir sonraki `get_next_line` çağrısı için saklar.

`get_next_line` : Projenin ana giriş noktasıdır. Dosya tanımlayıcısı (fd) ve `BUFFER_SIZE` geçerliliğini kontrol ettikten sonra süreci başlatır. `read_from_file` ile dosyadan veri okur; eğer okunan veri yoksa süreci güvenli bir boş dize ile devam ettirir. `get_current_line` ile döndürülecek satırı belleğe alır ve son olarak `update_state_buffer` ile statik değişkeni bir sonraki çağrı için güncelleyerek satırı kullanıcıya döndürür.

### Utility Functions

Projenin yardımcı fonksiyonları ana işleyişi destelemek açısından optimize edilmiştir.

- `ft_strchr` : Karakter dizisi içerisinde belli bir karakteri arar. Satır sonu (`\n`) karakterinin okunup okunmadığı kontrol etmek için kullanılmaktadır.

- `ft_strlen` : Karakter dizisinin uzunluğunu hesaplar. Dinamik bellek tahsisi sırasında buffer boyutlarını belirlemek için kullanılır.

- `ft_strjoin` : Mevcut statik veriyi yeni buffer veriyle birleştirilmesini sağlar. Bu satırın tamamı okunana kadar verinin birikmesini sağlar.

- `ft_strdup` : Verilen dizinin bir kopyasını oluşturur. Geri döndürülecek satırı veya bir sonraki okuma için kalan veriyi saklamak için kullanılmaktadır.

## INSTRUCTIONS

### Compilation

Bu proje bir ana dosya ile birlikte derlenmelidir. Derleme sırasında BUFFER_SIZE değerini belirlemek için `-D` bayrağı kullanılmalıdır. Eğer belirtilmezse headerda hali hazırda tanımlı olan değer üstünden çalışır. 

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_utils.c get_next_line.c main.c -o gnl
```

### Execution

Derleme sonrasında oluşan `gnl` dosyasını şu şekilde çalıştırabilirsiniz.

```bash
./gnl <dosya_adı> || ./gnl
```

## RESOURCES

Bu proje geliştirilirken aşağıda ki kaynaklardan yararlanılmıştır.

[Static Variables](https://www.geeksforgeeks.org/static-variables-in-c/) : Statik değişkenlerin ömrü ve kapsamı hakkında temel bilgiler.

[File Descriptor & Read Functions](https://man7.org/linux/man-pages/man2/read.2.html) : `read` fonksiyonunun sistem çağrısının dönüş değerleri ve dosya tanımlayıcılarının işleyişleri üstüne man sayfası.

## AI USAGE

- README Yazımı: Yapay zekadan README için bir taslak olabilmesi ve oluşturulabilmesi açısından yardım alınmıştır.

- Hata Ayıklama: Yazılan kodların hata durumları hakkında daha detaylı bilgi alınabilmesi için kullanılmıştır.

- Dokümantasyon Önerisi: Projenin en başında yapılması istenenlerin detaylıca anlatımı konusunda dokümantasyon önerisi.

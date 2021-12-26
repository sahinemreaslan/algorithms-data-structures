# algorithms-data-structures
<h2>Algorithms_Exercise_2 [TR]</h2>
<p>
A) Aşağıda formatı verilmiş olan Text dosyayı kullanarak Komşuluk Matris (Adjaceny
Matrix) yöntemiyle grafı oluşturunuz.<br>
B) Kullanıcıdan alınacak düğüm numarasının giriş derecesini ve çıkış derecesini
hesaplayarak ekrana yazdırınız.<br>
C) Graftaki toplam kenar sayısını hesaplayarak ekrana yazdırınız.<br>
D) Tüm grafı Depth First Search Algoritmasına göre dolaşarak, dolaşma sırasını ekrana
yazdırınız. Ayrıca ulaşma (d dizisi) ve işleme (f dizisi) zamanlarını da ekrana yazdırınız.<br>
Örnek Text Dosya Formatı: Her bir ifade boşluk karakteri ile ayrılmıştır. Ödev kontrol hocası
farklı text dosyalarda da denemeler yapabilecektir.</p>
<div align="center"><p>
0 1 0 1 0<br>
1 0 1 0 0<br>
0 0 0 0 0<br>
0 0 1 0 1<br>
0 0 0 1 0<br>
</p> </div>


<h2>Hash_data_structures _exercise_1 [TR]</h2>
<br>I will write the content</br>
<h2>Hash_data_structures _exercise_2 [TR]</h2>
<p>Müşteri numarası ve müşteri ad, soyad bilgilerinin müşteri numarası indeksine göre tutulacağı uygulama-1
ve uygulama-2 için iki ayrı hash tablosu için gerekli veri yapısını tanımlayarak aşağıdaki iki uygulamayı
gerçekleştiriniz. Hash tablo boyutu kullanıcıdan istenecektir ve hash fonksiyonu olarak key mod tablo boyutu
kullanılacaktır. Ekleme işlemi her iki uygulama içinde gerçekleştirilecektir.
<br>
Uygulama-1: Hash tablosuna ekleme fonksiyonu müşteri numarası, ad ve soyad bilgilerini parametre olarak
alarak, müşteri numarasına göre hash tablosuna ekleyecektir. Herhangi bir çakışma (collision) oluşması
durumunda ise hash tablosunun mevcut satırından itibaren adım adım bir sonraki satırdan itibaren ilk bulunan
boş satıra ekleme yapılacaktır. Bu esnada tablo dolu ise “tablo dolu” mesajı verilerek ekleme işlemi bitirilecektir.
<br>
Uygulama-2: Hash tablosuna ekleme fonksiyonu müşteri numarası, ad ve soyad bilgilerini parametre olarak
alarak, müşteri numarasına göre hash tablosuna ekleyecektir. Bu uygulamadaki hash tablosunda ilave olarak bir
sonraki gidilecek satır numarasını içeren bir link tutulacaktır. Herhangi bir çakışma oluşması durumunda ise
hash tablosunun başından sonuna doğru ilk bulunan boş satıra ekleme yapılacaktır ve ilgili linkler takip edilerek
takip listesinin son elemanının link alanı boş bulunan satır numarası olarak güncellenecektir. Bu esnada tablo
dolu ise “tablo dolu” mesajı verilerek ekleme işlemi bitirilecektir.
Her iki uygulama için;<br>
a) Her iki uygulama içinde yazacağınız iki ayrı arama fonksiyonu müşteri numara bilgisini alarak kayıtları
hash tablosunda arayacak ve kayıtların kaç adımda bulunduğunu geriye döndürecektir. (Aranan kayıt
bulunmazsa -1 geriye dönecektir)<br>
b) Her iki uygulama içinde yazacağınız iki ayrı listeleme fonksiyonu hash tablosunun içeriğini
listeleyecektir.</p>
<div align="center"><img src="https://user-images.githubusercontent.com/43322788/147419079-aaad4714-7cc9-40f1-b209-4732b1163c42.png" alt="hashing" width="500" height="600"></div>



# Приложение для синхронизации аудиотек на различных устройствах и стриминговых сервисах

# Проблема

У одного человека есть несколько устройств (или директорий), на каждом из этих устройств
 хранятся аудиофайлы и изображия (обложки альбомов) в сумме составляющие аудиотеку. При
 изменении аудиотеки (добавление/удаление/изменение файла) на одном устройстве - эти
 изменения не переносятся на другое устройство; и следовательно на разных устройствах
 хранятся разные аудиотеки

# Более подробное описание

Развитие устройств хранения информации позволило одному человеку иметь несколько носителей
 информации. При наличии у человека нескольких устройств, на которых хранится аудиотека, и
 при подключении этих устройств к приложению, приложение должно различать эти устройства
 между собой.
Развитие вычислительной техники позволило сохранять и распространять аудиофайлы в
 электронной форме с помощью стриминговых сервисов (таких как Spotify, Yandex Music и так
 далее), которые позволяют создавать списки избранного, которые представляют из себя
 удаленные аудиотеки, внутри себя. Этот факт еще больше осложняет процесс создания
 приложения для синхронизации аудиотек, добавляя в него необходимость устанавливать связь
 со стриминговыми сервисами.
Развитие технологий облачного хранения данных позволило переместить аудиотеки с локальных
 устройств в облачное хранилище. Количество сервисов для облачного хранения данных прямо
 пропорционально количеству аудиотек пользователя. Этот факт тоже осложняет процесс
 создание приложения для синхронизации аудиотек, добавляя в него необходимость
 поддерживать облачные хранилища данных.
Развитие операционных систем привело к появлению многих операционных систем, каждая из
 которых имеет свои особенности для работы в ней. Из множества операционных систем можно
 выделить следующие операционные системы: Windows, Linux, MacOS, iOS, Android.
 Современное приложение для синхронизации аудиотек должно иметь возможность запускаться
 на этих операционных системах.
Развитие современных интернет-технологий привело к переосмыслению понятия конечного
 пользователя сети интернет и введению концепции Web 3.0, которая является
 ориентированной (в отличии от концепции Web 2.0, которая ориентирована на потребление
 человеком) на компьютерные системы, которые занимаются обработкой информации полученной
 средствами сети-интернет. Этот факт еще больше осложняет создание приложения для
 синхронизации аудиотек, добавляя в него необходимость поддерживать управление
 приложением используя только консольный интерфейс (CLI - Console Line Interface),
 который можно легко обработать компьютерными средствами.
При синхронизации аудиотек может возникнуть ситуация, когда две (или более) аудиотеки
 имеют различия, и эти различия «перекрывают» друг друга – автор трека изменен в одном
 и том же файле, но после изменения авторы не совпадают. Приложение, должно
 информировать пользователя о том, что произошел «конфликт», и предлагать ему варианты
 решения этого «конфликта». Так же приложение должно иметь возможность включения
 автоматического разрешения «конфликтов» в будущем.
Резюмируя все выше сказанное можно отметить следующие функции, которые должны
 поддерживаться современным приложением для синхронизации аудиотек пользователя:

1. Синхронизация аудиотек с учетом внутренней информации .mp3 файлов
2. Синхронизация аудиотек на различных физических носителях данных
3. Синхронизация локальной аудиотеки со списками избранного которые были созданы
 в стриминговых сервисах
4. Синхронизация локальной аудиотеки с аудиотекой, расположенной в облачном хранилище
 данных
5. Возможность корректно работать на пользующихся популярностью, современных
 операционных системах
6. Возможность управления приложением используя только CLI
7. Возможность обнаружения и автоматического разрешения «конфликтов» синхронизации

Под понятием синхронизация понимается выполнение следующих функций:

1. Обнаружение различий между аудиотеками
   1. Различающиеся названия файлов
   2. Отличающиеся метаданные треков (автор, название, альбом, и т.д.)
   3. Отличающие звуковые дорожки файлов
   4. Перемещение файла
   5. Удаление файла
   6. Добавление файла
2. Устранение различий между аудиотеками
   1. Переименование файла
   2. Изменение метаданных треков
   3. Изменение звуковой дорожки
   4. Перемещение файла
   5. Удаление файла
   6. Копироание файла из аудиотеки в которой этот файл есть

# Задача

Реализовать программу которая делает аудиотеки на различных устройствах (или в различных
 директориях) одинаковыми

# Возможное решение проблемы

Создать файл который описывает аудиотеку и 

# UI

Приложение будет написанно в CLI с реализацией интерфейсов в графику и Web

1. Пользователь устанавливает приложение на каждое устройство
2. Открывает приложение
3. Вводит путь до своей аудиотеки
4. Выбирает где хранится аудиотека с которой необходимо синхронизироваться
   1. На его устройстве
   2. На сьемном носителе (флешка, CD, и т.д.)
   3. На другом устройстве
   4. (возможно) В каком то сервисе (Яндекс музыка)
   5. Все библиотки уже выбраны
5. Вводит комманду «Синхронизировать»
   1. Если аудиотеки совпадают
   2. Если сьемный носитель отсутствует
   3. Если другого устройства нет в сети
   4. Если сервис не доступен
   5. Если аудиотеки различаются

# Процесс поиска устройств конкретного пользователя в одноранговой сети

1. При желании пользователя добавить устройство (N+1) он должен вызвать
 функцию у того приложения которое находится на устройстве (N) по созданию
 приложения для конкретной платформы целевого устройства (N+1). По итогу 
 будут сгенерированы 2 файла: father.mac и AudioSync.(exe)
   1. В файле father.mac хранится MAC адрес родительского устройства (N) и имя
    пользователя 
   2. Файл AudioSync.(exe) представляет из себя установщик для приложения на
    выбранной платформе
2. Оба эти файла доставляются на устройство (N+1)
3. При первом запуске приложения на устройстве (N+1) приложение отправляет в
 сеть InARP запрос для выяснения текущего IP адреса (IP_N) устройства (N) с 
 MAC адресом записаным в father.mac
4. Приложение на устройстве (N+1) отправляет в сеть RARP (или его аналог, т.к.
 RARP устарел) запрос для получения своего текущего IP адреса (IP_N+1)
5. Приложение на устройстве (N+1) отправляет по IP адресу (IP_N) пакет данных
 со следующим содержанием:
   1. cUTF8String: имя пользователя
   2. MACAddrType: MAC адрес устройства (N+1)
   3. IPAddrType: IP адрес устройства (IP_N+1)
6. Приложение на устройстве (N) получает пакет данных отправленный устройством (N+1)
 и записывает их в network.csv

# План реализации

## Main

1. Получения от пользователя пути хранения аудиотеки [path = IO]
2. Инициализируем путь [hashForPath = initialize(path)]
3. Определение типа пути хранения
   1. ? На его устройстве
   2. ? На сьемном носителе (флешка, CD, и т.д.)
   3. ? На другом устройстве
   4. ? (возможно) В каком то сервисе (Яндекс музыка)
4. Добавление пути храниния в "базу путей"
5. Получение информации о всех доступных путях из "базы путей"

## string initialize(string path)

1. string initPrefix = ".init_hash"
2. string pathToHashForFile = concatenate(path, initPrefix)
3. string hashForFile
4. Путь инициализирован ?
   1. ? True [hashForFile = string(getFileContent_OS(pathToHashForFile))]
   2. ? False [
         1. pathIsDir_OS(path) ?
            1. ? True [hashForFile = reduce(getAllFilesAsStringFromDir_OS(path), fileReducerFunc)]
            2. ? False [hashForFile = hash(getFileContent_OS(path))]
      ]
5. writeToFile_OS(hashForFile, pathToHashForFile)
6. return hashForFile

## string fileReducerFunc(string oldHash, string path)

1. return concatenate(oldHash, initialize(path))


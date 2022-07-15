'A playlist'
class Song:
    def __init__(self, title, artist, album, rating, length, bitrate):
        self.__title = title
        self.__artist = artist
        self.__album = album
        self.__rating = rating
        self.__length = length
        self.__bitrate = bitrate
    
    def __repr__(self):
        return self.__title
    
    @property
    def artist(self):
        return self.__artist

    @property
    def title(self):
        return self.__title 

    @property
    def length(self):
        return self.__length

    @property
    def rating(self):
        return self.__rating

    @property 
    def bitrate(self):
        return self.__bitrate

    def rate(self):
        if self.__rating < 0:
            self.__rating = 0
        if self.__rating > 5:
            self.__rating = 5
  

class Playlist(Song):
    def __init__(self, playlist_name):
        self.__playlist_name =  playlist_name
        self.__songs = []

    @property 
    def songs(self):
        return self.__songs

    def add_song(self, song):
        self.__songs.append(song)

    def remove_song(self, song_name):
        self.__songs = [item for item in self.__songs if item.title != song_name]
    
    def total_length(self):
        tl = 0
        for item in self.__songs:
            tl = tl + item.length
        return tl

    def remove_disrated(self, rating):
        for item in self.__songs:
            if item.rating < rating:
                self.remove_song(item.title)
        
    def remove_bad_quality(self):
        for item in self.__songs:
            if item.bitrate < 50:
                self.remove_song(item.title)

    def show_artists(self):
        list_artists = []
        for item in self.__songs:
            if item.artist not in list_artists:
                list_artists.append(item.artist)
        return list_artists

    def __str__(self):
        s = ''
        for item in self.__songs:
            s += item.artist + ' ' + item.title + ' - ' + str(item.length) + '\n'
        return s



p = Playlist("Cool songs")
p.add_song(Song("girlbossing", "Iva", "PU$$YQUEEN", 5, 3.0, 200))
p.add_song(Song("QueenOfEverything", "Iva", "PU$$YQUEEN", 3, 13.2, 200))
p.add_song(Song("qkamacka", "Kari", "money", 5, 1.1, 49))
p.add_song(Song("qkamacka - remix", "Kari", "money", 5, 2.2, 10))
p.add_song(Song("ob sherek", "Sashka", "Sashka GG", 5, 2.0, 49))
print(p)
print(p.songs)
print(p.total_length())
p.remove_disrated(5)
print(p.songs)
p.remove_bad_quality()
print(p.songs)
print(p.show_artists())
print(p)


  
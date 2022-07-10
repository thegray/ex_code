# rename files in a folder, based on title name and extension type, increment 1 to the final name
# mostly used for movie series

import glob, os

def rename(dir, pattern, title):
    i = 1
    for pathAndFilename in glob.iglob(os.path.join(dir, pattern)):
        _, ext = os.path.splitext(os.path.basename(pathAndFilename))
        if i < 10:
            titlefinal = title + ' 0' + str(i)
        else:
            titlefinal = title + ' ' + str(i)
        os.rename(pathAndFilename, os.path.join(dir, titlefinal + ext))
        i += 1

## call the function, specify directory, pattern, and title pattern

if __name__ == '__main__':
    title = r'Yuru Camp'
    rename(r'D:\Data_Bangun\Anime\Yuru Camp', r'*.mkv', title)

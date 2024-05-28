To do :

Take the information about some function :
- [x] perror
    void perror(const char *s)
    display a systeme error message, idealy it need to be call just after errno , if not, i need to save the errno value
- [x] strerror
    char *strerror(int errnum)
    is used to get the description of an error code
    it give us the description of the error code or a message "Unknown error nnn" if the error code doesn't exist
- [x] exit
    void exit(int status)
    close normally a processus
    we can give every status we want, most common are EXIT_SUCCES & EXIT_FAILURE
- [x] all function from the math library (-lm compiler option)
- [x] all function of the MiniLibX

and some concept :
- [x] isometric projection

x = axis
y = ordinate
value = altitude/z

bonus :
i think it's better to do a verision without the bonus
and one with the bonus
- [x] one extra projection(parallel, conic, ...)
- [x] zoom in/out
- [x] translate the model
- [x] rotate the model
- [x] add one more bonus of our choice

for the compilation , add the folowing flag :
-lm -lmlx -lXext -lX11 -L (used to specify the path of the lib)

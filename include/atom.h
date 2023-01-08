#ifndef ATOM_H_
#define ATOM_H_

extern       int   Atom_length(const char *str);
extern const char *Atom_new   (const char *str, int len);
extern const char *Atom_string(const char *str);
extern const char *Atom_int   (long n);

#endif  // ATOM_H_

#ifndef __INTRINS_H__
#define __INTRINS_H__
 
extern void          _nop_     (void);
extern unsigned char _cror_    (unsigned char val, unsigned char n);
extern unsigned int  _iror_    (unsigned int val,  unsigned char n);
extern unsigned long _lror_    (unsigned long val, unsigned char n);
extern unsigned char _crol_    (unsigned char val, unsigned char n);
extern unsigned int  _irol_    (unsigned int val,  unsigned char n);
extern unsigned long _lrol_    (unsigned long val, unsigned char n);
extern unsigned char _chkfloat_(float);
extern void          _push_    (unsigned char _sfr);
extern void          _pop_     (unsigned char _sfr);
 
#endif
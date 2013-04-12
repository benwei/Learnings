#ifndef __SOCASE_H__
#define __SOCASE_H__

#ifdef __cplusplus__
extern "C" {
#endif /* __cplusplus__ */

#define SO_ASCII_ART_OK   'O'
#define SO_ASCII_ART_FAIL 'X'

#define SO_CASE_EQUAL(l,r) ((l==r) ? SO_ASCII_ART_OK: SO_ASCII_ART_FAIL)

#ifdef __cplusplus__
extern "C" {
#endif /* __cplusplus__ */

#endif /* __SOCASE_H__ */

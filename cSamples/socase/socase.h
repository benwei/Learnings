/*
 * Written By Ben Wei ben@staros.mobi 2014
 **/

#ifndef __SOCASE_H__
#define __SOCASE_H__

#ifdef __cplusplus__
extern "C" {
#endif /* __cplusplus__ */

#define SO_ASCII_ART_OK   'O'
#define SO_ASCII_ART_FAIL 'X'

#define SO_CASE_EQUAL(l,r) ((l==r) ? SO_ASCII_ART_OK: SO_ASCII_ART_FAIL)

/* macro and defintions for bool value */
#define SO_STRING_TRUE "true"
#define SO_STRING_FALSE "false"
#define SO_ASCII_BOOL(bool_value) ((bool_value) ? SO_STRING_TRUE: SO_STRING_FALSE) 

#ifdef __cplusplus__
extern "C" {
#endif /* __cplusplus__ */

#endif /* __SOCASE_H__ */

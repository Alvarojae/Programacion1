/*
 * parser.h
 *
 *  Created on: 28 Oct 2020
 *      Author: Alvaro
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EnvioFromTextDos(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EnvioFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */

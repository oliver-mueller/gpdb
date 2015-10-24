/*-------------------------------------------------------------------------
*
* pg_partition.h
*	  internal specifications of the partition configuration.
*
* Portions Copyright (c) 2008-2010, Greenplum Inc.
*-------------------------------------------------------------------------
*/
#ifndef PG_PARTITION_H
#define PG_PARTITION_H


#include "catalog/genbki.h"

/* TIDYCAT_BEGINDEF

   CREATE TABLE pg_partition
   with (relid=5010, content=MASTER_ONLY)
   (
   parrelid       oid,
   parkind        "char",
   parlevel       smallint,
   paristemplate  boolean,
   parnatts       smallint,
   paratts        int2vector,
   parclass       oidvector
   );

   create unique index on pg_partition(oid) with (indexid=5012);
   create index on pg_partition(parrelid) with (indexid=5013);
   create index on pg_partition(parrelid, parlevel, paristemplate) with (indexid=5017,indexname=pg_partition_parrelid_parlevel_istemplate_index);

   alter table pg_partition add fk parrelid on pg_class(oid);
   alter table pg_partition add vector_fk parclass on pg_opclass(oid);

   TIDYCAT_ENDDEF
*/

/* TIDYCAT_BEGIN_CODEGEN 

   WARNING: DO NOT MODIFY THE FOLLOWING SECTION: 
   Generated by tidycat.pl version 33
   on Wed Aug 15 14:17:41 2012
*/


/*
 TidyCat Comments for pg_partition:
  Table has an Oid column.
  Table does not have static type (only legal for pre-3.3 tables). 
  Table contents are only maintained on MASTER.

*/

/* ----------------
 *		pg_partition definition.  cpp turns this into
 *		typedef struct FormData_pg_partition
 * ----------------
 */
#define PartitionRelationId	5010

CATALOG(pg_partition,5010)
{
	Oid			parrelid;		
	char		parkind;		
	int2		parlevel;		
	bool		paristemplate;	
	int2		parnatts;		
	int2vector	paratts;		
	oidvector	parclass;		
} FormData_pg_partition;


/* ----------------
 *		Form_pg_partition corresponds to a pointer to a tuple with
 *		the format of pg_partition relation.
 * ----------------
 */
typedef FormData_pg_partition *Form_pg_partition;


/* ----------------
 *		compiler constants for pg_partition
 * ----------------
 */
#define Natts_pg_partition				7
#define Anum_pg_partition_parrelid		1
#define Anum_pg_partition_parkind		2
#define Anum_pg_partition_parlevel		3
#define Anum_pg_partition_paristemplate	4
#define Anum_pg_partition_parnatts		5
#define Anum_pg_partition_paratts		6
#define Anum_pg_partition_parclass		7


/* TIDYCAT_END_CODEGEN */

#endif   /* PG_PARTITION_H */

/*
 * csim.c
 *
 *  Created on: Nov 20, 2017
 *      ddelvecchio@unm.edu
 *      Author: Dominic Del Vecchio
 */
#include "cachelab.h"
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <strings.h>


//Fundamental parameters

//number of sets
int S;
//number of lines per set
int E;
int B;
//address size set to 64 as all addresses will be 64 bytes
int m = 64;

unsigned long long s;
unsigned long long b;
unsigned long long tag;

//number of hits, misses and evictions
int hits = 0;
int misses = 0;
int evictions = 0;
//flag for LRU
int lru = 0;
//structure to hold each line of cache
    typedef struct
    {
      unsigned long long tagline;
      unsigned long long set;
      int lastUsed;
    }line;


//fills the cache with lines and sets the tag for -1
void buildCache(line cache[S][E])
{

  line currentLine;
  currentLine.tagline = -1;
  currentLine.lastUsed = 0;

  for(int i=0; i<S; i++)
    {

      for(int j=0; j<E; j++)
	{
	  cache[i][j] = currentLine;
	}
    }
}

/*finds the least recently used line to evict. Uses a global counter that
 * tracks all of the hits. Each time a cache line is used it is assigned
 * the current value of the global counter. This function finds the line
 * with the lowest value which is the least recently used
 */
int LRU(line cache[S][E], unsigned long long set)
{
  //if(E==1) return 0;
  int least = cache[set][0].lastUsed;
  int index = 0;
  for(int i=0; i<E; i++)
    {
      if(least >= cache[set][i].lastUsed)
	{
	  least = cache[set][i].lastUsed;
	  index = i;
	}
    }
  return index;
}
//actual simulation of the cache. takes a  pointer to the 2d cache array and a memory address
void cacheSim( line cache[S][E], unsigned long long address)
{
  //flag for hit
  int hit = 0;
  //flag for empty line
  int emptyFlag = 0;
  int emptyLine = 0;
  line currentLine;
  currentLine.tagline = address >> (s+b);
  currentLine.set =  address << tag;
  currentLine.set = currentLine.set >> (tag + b);
  for(int i=0; i<E; i++)
    {
      if(cache[currentLine.set][i].tagline == -1)
	{
	  emptyFlag = 1;
	  emptyLine = i;
	}
      if(cache[currentLine.set][i].tagline == currentLine.tagline)
	{
	  hits++;
	  hit = 1;
	  lru++;
	  cache[currentLine.set][i].lastUsed = lru;
	}
    }

  if(hit == 0 && emptyFlag ==1)
    {
      cache[currentLine.set][emptyLine].tagline = currentLine.tagline;
      cache[currentLine.set][emptyLine].lastUsed = lru;
      misses++;
    }
  if(hit == 0 && emptyFlag ==0)
    {
      int index = LRU(cache,currentLine.set);
      cache[currentLine.set][index].tagline = currentLine.tagline;
      cache[currentLine.set][index].lastUsed = lru;
      misses++;
      evictions++;
    }


}
//main function reads in the arguments and files while implement the cache simulation
int main(int argc, char **argv)
{

  FILE *file;
  //storage variable for the memory address
  unsigned long long address;
  //storage variable for the size not actually used in simulation
  int size;
  char *traceFile;
  char c;
  //read in command line arguments and assign to global variables
  while((c=getopt(argc,argv,"s:E:b:t:vh")) != -1)
    {
      switch(c)
	{
	case 's':
	  s = atoi(optarg);
	  break;
	case 'E':
	  E = atoi(optarg);
	  break;
	case 'b':
	  b = atoi(optarg);
	  break;
	case 't':
	  traceFile = optarg;
	  break;
	case 'h':
	  exit(0);
	default:
	  exit(1);
	}
    }
  //compute missing cache values from command line args
  S = pow(2, s);
  B = pow(2, b);
  tag = m -(s + b);
  //initialze cach as 2d array of the line structure
  //line **cache = malloc(S * E * sizeof(**cache));
  line cache[S][E];
  buildCache(cache);
  //open trace file
  file  = fopen(traceFile, "r");
  /*
   * read all memory reference until the file is empty
   * and call the cache simulator or ignore if I. M calls the simulator
   * twice. I orginally had a function for S and L and another for M, but then I realized
   * by calling it twice it will get two hits or a miss and a hit without all of the
   * extra code.
   */
  if (file != NULL) {
    while (fscanf(file, " %c %llx,%d", &c, &address, &size) == 3) {


      switch(c) {
      case 'I':
	break;
      case 'L':
	cacheSim(cache, address);
	break;
      case 'S':
	cacheSim(cache, address);
	break;
      case 'M':
	cacheSim(cache, address);
	cacheSim(cache, address);
	break;
      default:
	break;
      }
    }
  }
  printSummary(hits, misses, evictions);
  return 0;
}






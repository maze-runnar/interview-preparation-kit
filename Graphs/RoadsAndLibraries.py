#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the roadsAndLibraries function below.
def roadsAndLibraries(n, c_lib, c_road, cities):
    total = 0
    if c_lib < c_road:
        total = n*c_lib
    else:       
        neighbours = {}
        visited = [False] * n
        connectedComponents = 0
        nodes_per_cluster = {}

        def dfs(i,cluster):
            if not visited[i]:
                nodes_per_cluster[cluster] = (
                    nodes_per_cluster.get(cluster,0) + 1)
            visited[i] = True
            my_neighbours = []
            try:
                my_neighbours = neighbours[i+1] 
            except KeyError as ke:
                pass
            for city_id in my_neighbours:
                if not visited[city_id-1]:
                    dfs(city_id-1,cluster)

        for road in cities:
            neighbours[road[0]] = (
                neighbours.get(road[0],[]) + [road[1]])
            neighbours[road[1]] = (
                neighbours.get(road[1],[]) + [road[0]])
        
        for i in range(n):
            if not visited[i]:
                dfs(i,i)
                connectedComponents += 1
     
        roads = sum(x-1 for x in nodes_per_cluster.values())
            
        total = c_road * roads + c_lib * connectedComponents
    return total

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        nmC_libC_road = input().split()

        n = int(nmC_libC_road[0])

        m = int(nmC_libC_road[1])

        c_lib = int(nmC_libC_road[2])

        c_road = int(nmC_libC_road[3])

        cities = []

        for _ in range(m):
            cities.append(list(map(int, input().rstrip().split())))

        result = roadsAndLibraries(n, c_lib, c_road, cities)

        fptr.write(str(result) + '\n')

    fptr.close()

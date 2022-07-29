if __name__ == '__main__':
    dimension_1 = int(input())
    dimension_2 = int(input())
    dimension_3 = int(input())
    expected_sum = int(input())
    
    permutations = [[permutation_1, permutation_2, permutation_3] for 
                    permutation_1 in range(dimension_1+1) for 
                    permutation_2 in range (dimension_2+1) for 
                    permutation_3 in range(dimension_3+1) if 
                    permutation_1+permutation_2+permutation_3 != expected_sum]
                    
    print(permutations)

class Solution(object):
	def rotate(self, matrix):
		n = len(matrix)
		i = 0
		while i < n / 2:
			j = 0
			while j < math.ceil((n) / 2.):
				temp = matrix[i][j]
				matrix[i][j] = matrix[n - 1 - j][i]
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
				matrix[j][n - 1 - i] = temp
				j += 1
			i += 1
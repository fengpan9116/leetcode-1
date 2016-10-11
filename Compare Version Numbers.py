class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = version1.split('.')
        v2 = version2.split('.')
        i = 0
        while True:
            if i >= len(v1) or i >= len(v2):
                if len(v1) < len(v2):
                    for i in range(i, len(v2)):
                        if int(v2[i]) != 0: return -1
                    return 0

                elif len(v1) > len(v2):
                    for i in range(i, len(v1)):
                        if int(v1[i]) != 0: return 1
                    return 0

                else:
                    return 0

            if int(v1[i]) > int(v2[i]): return 1
            elif int(v1[i]) < int(v2[i]): return -1
            i += 1

        return 0
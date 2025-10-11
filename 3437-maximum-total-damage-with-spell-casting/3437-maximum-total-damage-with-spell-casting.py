class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        damage_freq = defaultdict(int)
        for dmg in power:
            damage_freq[dmg] += 1

        unique_damage = sorted(damage_freq.keys())

        if len(unique_damage) == 1:
            return unique_damage[0] * damage_freq[unique_damage[0]]

        n = len(unique_damage)
        dp = [0] * (n + 1)
        
        for i in range(1, n + 1):
            current_damage = unique_damage[i - 1] * damage_freq[unique_damage[i - 1]]

            take = current_damage

            for j in range(i - 2, -1, -1):
                if unique_damage[i - 1] - unique_damage[j] > 2:
                    take += dp[j + 1]
                    break

            dont_take = dp[i - 1]

            dp[i] = max(take, dont_take)
        
        return dp[n]
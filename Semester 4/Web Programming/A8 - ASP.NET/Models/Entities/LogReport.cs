namespace lab10_webbb.Models.Entities
{
    public class LogReport
    {
        public int Id { get; set; }
        public string Type { get; set; }

        public string Severity { get; set; }

        public DateTime DateCreated { get; set; }

        public string UserId { get; set; }

        public string Message { get; set; }
    }
}
